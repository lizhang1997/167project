#include <RoboCatServerPCH.h>


PubgServer::PubgServer()
{
    
}

void PubgServer::HandleDying()
{
    NetworkManagerServer::sInstance->UnregisterGameObject( this );
}


bool PubgServer::HandleCollisionWithCat( RoboCat* inCat )
{
        SetDoesWantToDie( true );
        
        //ScoreBoardManager::sInstance->IncScore( inCat->GetPlayerId(), 1 );
		static_cast< RoboCatServer* >(inCat)->TakeHeal();

    
    return false;
}



