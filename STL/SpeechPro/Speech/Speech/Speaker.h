#pragma once

#ifndef _SPEAKER_H_
#define _SPEAKER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "SpeechManager.h"


using namespace std;

//选手类
class Speaker
{
public:
	string m_name;
	double m_score[2];//最多两轮比赛；
};



#endif