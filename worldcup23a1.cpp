#include "worldcup23a1.h"
#include "Team.h"
#include "Player.h"

world_cup_t::world_cup_t() :m_topScorer(nullptr), m_numPlayers(0)
{
		//and add the rest
        //TODO: יש טעם להוסיף את האחרים או שזה כבר אותחל?
}

world_cup_t::~world_cup_t()
{
	// TODO: check if needed: delete m_topScorer
    // TODO: check if all the rest deleted automatically because destroying this call each one destructor
	// TODO: how to destruct an object 
	delete m_topScorer;
    AVLTree<Player*, SortByScore> m_playersByScore;
    AVLTree<Player*, SortById> m_playersById;
	AVLTree<Team*, SortTeamById> m_teams;
	AVLTree<Team*, SortTeamById> m_validTeams;
    twoWayList<Player*> m_playersListByScore;
}


StatusType world_cup_t::add_team(int teamId, int points)
{
	// TODO: Your code goes here
	if(teamId<=0 || points<0){
		return StatusType::INVALID_INPUT;
	}

    if(m_teams.find(teamId)){
        return StatusType::FAILURE;
    }
	Team* newTeam;
    try{
		newTeam = new Team(teamId, points);
		m_teams.insert(newTeam);
    }
    catch(std::bad_alloc&){
        delete newTeam;
        return StatusType::ALLOCATION_ERROR;
    }
	return StatusType::SUCCESS;
}

StatusType world_cup_t::remove_team(int teamId)
{
    if(teamId<=0){
		return StatusType::INVALID_INPUT;
	}
    if((!m_teams.find(teamId)) || !(*m_teams.find(teamId)->getData())->isEmptyTeam()){
        return StatusType::FAILURE;
    }
    try{
        m_teams.remove(teamId);
        if((m_validTeams.find(teamId)) && (*m_validTeams.find(teamId)->getData())->isEmptyTeam()){
            m_validTeams.remove(teamId);
        }
    }
    catch(std::bad_alloc&){
        return StatusType::ALLOCATION_ERROR;
    }
	return StatusType::SUCCESS;
}

StatusType world_cup_t::add_player(int playerId, int teamId, int gamesPlayed,
                                   int goals, int cards, bool goalKeeper)
{
	// TODO: Your code goes here
    if(playerId<=0 || teamId<=0 || gamesPlayed<0 || goals<0 ||cards<0 || (gamesPlayed=0 && (goals>0 || cards>0))){
        return StatusType::INVALID_INPUT;
    }


	// can a pointer creation fail?
    Team* currentTeam = *m_teams.find(teamId)->getData();
    if(currentTeam== nullptr || *m_teams.find(teamId)->getData() == nullptr || 
	*m_playersById.find(playerId)->getData()!=nullptr){
        return StatusType::FAILURE;
    }
    try{
      //  Player(int playerId, int teamId, int gamesPlayed, int goals, int cards, bool goalkeeper); // check for consts
        auto newPlayer = new Player(playerId, teamId, gamesPlayed, goals, cards, goalKeeper);
		newPlayer->setTeamPtr(currentTeam);

		newPlayer->setDequePtr(nullptr);
		//conncet to deque;
        m_playersById.insert(newPlayer);
		m_playersByScore.insert(newPlayer);
		//currentTeam.
		
	}
    catch(std::bad_alloc&){
		return StatusType::ALLOCATION_ERROR;
    }

	return StatusType::SUCCESS;
}

StatusType world_cup_t::remove_player(int playerId)
{
	// TODO: Your code goes here
	if(playerId<=0){
		return StatusType::INVALID_INPUT;
	}

	Player* playerToDelete=*m_playersById.find(playerId)->getData();
	if(playerToDelete==nullptr){
		return StatusType::FAILURE;
	}

	try{

	}
	catch(...){
		;
	}
	

	return StatusType::SUCCESS;
}

StatusType world_cup_t::update_player_stats(int playerId, int gamesPlayed,
                                        int scoredGoals, int cardsReceived)
{
	// TODO: Your code goes here
	if(playerId<=0 || gamesPlayed<0 || scoredGoals<0 || cardsReceived<0){
		return StatusType::INVALID_INPUT;
	}

	return StatusType::SUCCESS;
}
StatusType world_cup_t::play_match(int teamId1, int teamId2)
{
	// TODO: Your code goes here
	if(teamId1<=0 || teamId2<=0 || teamId1==teamId2){
		return StatusType::INVALID_INPUT;
	}
	
	BinNode<Team*>* team1Ptr = m_teams.find(teamId1);
	BinNode<Team*>* team2Ptr = m_teams.find(teamId2);
	if(team1Ptr == nullptr || team2Ptr == nullptr){
		return StatusType::FAILURE;
	}
	Team* team1 = *team1Ptr->getData();
	Team* team2 = *team2Ptr->getData();
	if(team1->getTotalPlayers()<11 ||team2->getTotalPlayers()<11){
		return StatusType::FAILURE;
	}
	int power1 = team1->getPoints()+team1->getTotalGoals()-team1->getTotalCards();
	int power2 = team2->getPoints()+team2->getTotalGoals()-team2->getTotalCards();
	
	if(power1 == power2){
		team1->updatePoints(DRAW);
		team2->updatePoints(DRAW);
	}

	else if(power1 > power2){
		team1->updatePoints(WIN);
	}
	else{
		team2->updatePoints(WIN);
	}
	
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_num_played_games(int playerId)
{
	// TODO: Your code goes here
	if(playerId<=0){
		return output_t<int>(StatusType::INVALID_INPUT);
	}

	return 22;
}

output_t<int> world_cup_t::get_team_points(int teamId)
{
	// TODO: Your code goes here
	if(teamId<=0){
		return output_t<int>(StatusType::INVALID_INPUT);
	}

	return 30003;
}

StatusType world_cup_t::unite_teams(int teamId1, int teamId2, int newTeamId)
{
	// TODO: Your code goes here
	if(newTeamId<=0 || teamId1<=0 || teamId2<=0 || teamId1==teamId2){
		return StatusType::INVALID_INPUT;
	}

	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_top_scorer(int teamId)
{
	if(teamId==0){
		return output_t<int>(StatusType::INVALID_INPUT);
	}

	if(teamId>0){
		// check if team 
		if(m_numPlayers==0){
			return output_t<int>(StatusType::FAILURE);
		}

		return output_t<int>(m_topScorer->getPlayerId());
	}
	
	//search for the team if couldnt find throw error
	return output_t<int>(6);//should be the id of the top scorer in the team
}

output_t<int> world_cup_t::get_all_players_count(int teamId)
{
	if(teamId==0){
		return output_t<int>(StatusType::INVALID_INPUT);
	}

	if(teamId<0){
		return output_t<int>(m_numPlayers);
	}
	
	//search for the team if couldnt find throw error
	return output_t<int>(6);//should by the number of players in the team
}

StatusType world_cup_t::get_all_players(int teamId, int *const output)
{
	// TODO: Your code goes here
	if(output==nullptr || teamId==0){
		return StatusType::INVALID_INPUT;
	}

    output[0] = 4001;
    output[1] = 4002;
	return StatusType::SUCCESS;
}

output_t<int> world_cup_t::get_closest_player(int playerId, int teamId)
{
	// TODO: Your code goes here
	if(teamId<=0 || playerId<=0){
		return StatusType::INVALID_INPUT;
	}
	return 1006;
}

output_t<int> world_cup_t::knockout_winner(int minTeamId, int maxTeamId)
{
	// TODO: Your code goes here
	if(minTeamId<0 || maxTeamId<0 || maxTeamId<minTeamId){
		return StatusType::INVALID_INPUT;
	}
	
	return 2;
}

