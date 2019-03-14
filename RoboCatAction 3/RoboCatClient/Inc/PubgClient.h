class PubgClient : public Pubg
{
public:
    static    GameObjectPtr    StaticCreate()        { return GameObjectPtr( new PubgClient() ); }
    
    virtual void        Read( InputMemoryBitStream& inInputStream ) override;
    
protected:
    PubgClient();
    
private:
    
    SpriteComponentPtr    mSpriteComponent;
};

