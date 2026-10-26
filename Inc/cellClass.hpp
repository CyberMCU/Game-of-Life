#ifndef CELLCLASS_HPP
#define CELLCLASS_HPP

class Cell{
    private:
    bool m_alive;
    
    public:
    void setAlive(bool value);
    bool isAlive(void) const;
};

#endif