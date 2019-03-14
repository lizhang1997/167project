class Pubg : public GameObject
{
public:
    
    CLASS_IDENTIFICATION( 'PUBG', GameObject )
    
    enum EYarnReplicationState
    {
        EPRS_Pose            = 1 << 0,
        EPRS_AllState    = EPRS_Pose
    };
    
    static    GameObject*    StaticCreate() { return new Pubg(); }
    
    virtual uint32_t    GetAllStateMask()    const override    { return EPRS_AllState; }
    
    virtual uint32_t    Write( OutputMemoryBitStream& inOutputStream, uint32_t inDirtyState ) const override;
    //virtual void        Read( InputMemoryBitStream& inInputStream ) override;
   
    
    void        SetPlayerId( int inPlayerId )    { mPlayerId = inPlayerId; }
    int            GetPlayerId() const                { return mPlayerId; }
    
    
    
    virtual bool HandleCollisionWithCat( RoboCat* inCat ) override;
    
protected:
    Pubg();
    

    int            mPlayerId;
    
};

typedef shared_ptr< Pubg >    PubgPtr;

