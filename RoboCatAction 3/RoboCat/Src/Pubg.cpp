#include <RoboCatPCH.h>

Pubg::Pubg()
{
    SetScale( GetScale() * 0.1f );
    SetCollisionRadius( 0.25f );
}


bool Pubg::HandleCollisionWithCat( RoboCat* inCat )
{
    ( void ) inCat;
    return false;
}



uint32_t Pubg::Write( OutputMemoryBitStream& inOutputStream, uint32_t inDirtyState ) const
{
    uint32_t writtenState = 0;
    
    if( inDirtyState & EPRS_Pose )
    {
        inOutputStream.Write( (bool)true );
        
        Vector3 location = GetLocation();
        inOutputStream.Write( location.mX );
        inOutputStream.Write( location.mY );
        
        //inOutputStream.Write( GetRotation() );
        
        writtenState |= EPRS_Pose;
    }
    else
    {
        inOutputStream.Write( (bool)false );
	}
    
    return writtenState;
}


