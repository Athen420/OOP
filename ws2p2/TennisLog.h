#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <string>
#include <iostream>

namespace sdds
{
    struct TennisMatch
    {
        std::string tournamentID;
        std::string tournamentName;
        int matchID = -1;
        std::string winner;
        std::string loser;
    };
    std::ostream& operator<<(std::ostream& os, const TennisMatch& match);

    class TennisLog
    {
    private:
        TennisMatch** matches = nullptr;
        size_t count = 0;
    public:
        TennisLog();
        TennisLog(std::string filename);
        TennisLog(const TennisLog& other);
        TennisLog(TennisLog&& other);
        TennisLog& operator=(const TennisLog& other);
        TennisLog& operator=(TennisLog&& other);
        ~TennisLog();
        void addMatch(TennisMatch& match);
        TennisLog findMatches(std::string playerName) const;
        TennisMatch operator[](size_t idx) const;
        operator size_t() const;
    };
    
} // namespace sdds


#endif // SDDS_TENNISLOG_H
