//
// Created by Sysadmin on 03/05/2026.
//

#ifndef CPLUSPLUS_BUGGAME_SILVER_CRAWLER_H
#define CPLUSPLUS_BUGGAME_SILVER_CRAWLER_H
#include <cstdlib>
#include <iostream>
#include <string>

#include "../bugs/Bug.h"


class Crawler : public Bug
{
    public:
      using Bug::Bug;

    void move() override;
    void display() const override;

};


#endif //CPLUSPLUS_BUGGAME_SILVER_CRAWLER_H