class PubgServer : public Pubg
{
public:
    static GameObjectPtr    StaticCreate() { return NetworkManagerServer::sInstance->RegisterAndReturn( new PubgServer() ); }
    void HandleDying() override;
    
    virtual bool        HandleCollisionWithCat( RoboCat* inCat ) override;
    
    
protected:
    PubgServer();
    
};

