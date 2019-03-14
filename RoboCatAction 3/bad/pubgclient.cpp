#include "RoboCatClientPCH.h"


pubgclient::pubgclient()
{
    mSpriteComponent.reset( new SpriteComponent( this ) );
    mSpriteComponent->SetTexture( TextureManager::sInstance->GetTexture( "pubg" ) );
}


void pubgclient::Read( InputMemoryBitStream& inInputStream )
{
    bool stateBit;
    
    inInputStream.Read( stateBit );
    if( stateBit )
    {
        Vector3 location;
        inInputStream.Read( location.mX );
        inInputStream.Read( location.mY );
        SetLocation( location );
      
    }
    
    inInputStream.Read( stateBit );
    if( stateBit )
    {
        inInputStream.Read( mPlayerId, 8 );
    }
    inInputStream.Read( stateBit );
    if( stateBit )
    {
        inInputStream.Read( mPOWERUP, 8 );
    }
}

