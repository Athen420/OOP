#include "LineManager.h"
#include "Utilities.h"
#include <fstream>
#include <algorithm>
#include <iterator>

namespace sdds
{
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        Utilities ut;
        ut.setDelimiter('|');
        std::fstream f(file);

        if (!f) throw("File not found");

        std::string line;
        while (std::getline(f, line)) {
            size_t nPos = 0;
            bool isMore = true;
            bool isLastStation = false;
            std::string station = ut.extractToken(line, nPos, isMore);
            std::string nextStation;
            if (isMore) nextStation = ut.extractToken(line, nPos, isMore);
            else isLastStation = true;

            std::vector<Workstation*>::const_iterator stationItr;
            std::vector<Workstation*>::const_iterator nextStationItr;

            stationItr = std::find_if(stations.begin(), stations.end(), [=](Workstation* workstation) { return workstation->getItemName() == station; });
            if (!isLastStation) nextStationItr = std::find_if(stations.begin(), stations.end(), [=](Workstation* workstation) { return workstation->getItemName() == nextStation; });

            if (!isLastStation) (*stationItr)->setNextStation(*nextStationItr);

            m_activeLine.push_back(*stationItr);
        }
        m_cntCustomerOrder = g_pending.size();

        std::vector<Workstation*> lst2 = m_activeLine;
        Workstation* firstStation = nullptr;

        std::any_of(m_activeLine.begin(), m_activeLine.end(), [&lst2, &firstStation](Workstation* i) {
            bool isFirstStation = !std::any_of(lst2.begin(), lst2.end(), [&i](Workstation* j) { return j->getNextStation() != nullptr && j->getNextStation()->getItemName() == i->getItemName(); });
            if (isFirstStation) {
                firstStation = i;
                return true;
            }
            return false;
        });

        m_firstStation = firstStation;
    }

    void LineManager::reorderStations() {
        Workstation* firstNode = m_firstStation;

        std::vector<Workstation*> new_activeLine;
        while (firstNode != nullptr) {
            new_activeLine.push_back(firstNode);
            firstNode = firstNode->getNextStation();
        }

        m_activeLine = new_activeLine;
    }

    bool LineManager::run(std::ostream& os) {
        static int itr = 1;
        os << "Line Manager Iteration: " << itr << std::endl;

        if (g_pending.size() > 0) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&os](Workstation* workstation) { workstation->fill(os); });
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [](Workstation* workstation) {
            workstation->attemptToMoveOrder();
        });
        itr++;

        if (g_completed.size() + g_incomplete.size() < m_cntCustomerOrder) return false;
        return true;
    }

    void LineManager::display(std::ostream& os) const {
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&os](const Workstation* workstation) { workstation->display(os); });
    }
} // namespace sdds
