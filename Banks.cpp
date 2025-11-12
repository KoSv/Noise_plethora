// Noise Plethora
// Copyright (c) 2021 Befaco / Jeremy Bernstein
// Open-source software
// Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported
// See LICENSE.txt for the complete license text

#include "Banks.hpp"
#include "Banks_Def.hpp"

const Bank::BankElem Bank::defaultElem = {"", 1.0};

Bank::Bank() {
  programs.fill(defaultElem);
}

Bank::Bank(const BankElem& p1, const BankElem& p2, const BankElem& p3,
           const BankElem& p4, const BankElem& p5, const BankElem& p6,
           const BankElem& p7, const BankElem& p8, const BankElem& p9,
           const BankElem& p10)
       : programs{p1, p2, p3, p4, p5, p6, p7, p8, p9, p10}
     { }

const char* Bank::getProgramName(int i) {
  if (i >= 0 && i < programsPerBank) {
    return programs[i].name.c_str();
  }
  return "";
}

float Bank::getProgramGain(int i) {
  if (i >= 0 && i < programsPerBank) {
    return programs[i].gain;
  }
  return 1.0;
}

int Bank::getSize() {
  int size = 0;
  for (auto it = programs.begin(); it != programs.end(); it++) {
	  if ((*it).name == "") {
		  break;
	  }
	  size++;
  }
  return size;
}

static const Bank bank1 BANKS_DEF_1; // Banks_Def.hpp
static const Bank bank2 BANKS_DEF_2;
static const Bank bank3 BANKS_DEF_3;
static const Bank bank4 BANKS_DEF_4;
static const Bank bank5 BANKS_DEF_5;
static std::array<Bank, numBanks> banks { bank1, bank2, bank3, bank4, bank5 };

Bank& getBankForIndex(int i) {
  if (i < 0) i = 0;
  if (i >= programsPerBank) i = (programsPerBank - 1);
  return banks[i];
}
