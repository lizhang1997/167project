#include "RoboCatClientPCH.h"


PubgClient::PubgClient()
{
    mSpriteComponent.reset( new SpriteComponent( this ) );
    mSpriteComponent->SetTexture( TextureManager::sInstance->GetTexture( std::string("pubg") ) );
}


void PubgClient::Read(InputMemoryBitStream& inInputStream)
{
	bool stateBit;

	inInputStream.Read(stateBit);
	if (stateBit)
	{
		Vector3 location;
		inInputStream.Read(location.mX);
		inInputStream.Read(location.mY);
		SetLocation(location);

	}
	else SetDoesWantToDie(true);


}



