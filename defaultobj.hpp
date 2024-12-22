
typedef struct
{
    int size_x;
    int size_y;
    int velocity_x;
    int velocity_y;

}stats;


class defaultobj
{
    protected:
        stats* objectstats;
    
    public:
        defaultobj();
        ~defaultobj();

        stats* getStats() const;
        

};