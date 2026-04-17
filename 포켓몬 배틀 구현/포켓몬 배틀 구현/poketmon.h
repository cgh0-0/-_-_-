#pragma once

class poketmon
{
public:
    int* HP;
    int damage;
    int specialskilldamage;

    void damaged(poketmon& a);
    void attack(poketmon& a);
    void healing(poketmon& other);
    void specialattack(poketmon& other);
};

class pickachu : public poketmon
{public:
    pickachu();
    ~pickachu();
};

class turtle : public poketmon
{
public:
    turtle();
    ~turtle();
};

class paili : public poketmon
{
public:
    paili();
    ~paili();
};