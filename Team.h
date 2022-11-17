
#ifndef EX1_Team_H
#define EX1_Team_H

class Team{
    public:
        Team(int teamId, int points);
        ~Team() = default;
    
    private:
        int m_teamId;
        int m_points;
};

#endif //EX1_Team_H
