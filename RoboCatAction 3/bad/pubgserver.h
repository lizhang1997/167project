class pubgserver : public pubg
{
public:
    static GameObjectPtr    StaticCreate() { return NetworkManagerServer::sInstance->RegisterAndReturn( new pubgserver() ); }
    void HandleDying() override;
    
    virtual bool        HandleCollisionWithCat( RoboCat* inCat ) override;
    
    virtual void Update() override;
    
protected:
    pubgserver();
    
private:
    float mTimeToDie;
    
};

