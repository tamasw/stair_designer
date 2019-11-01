/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.h
 * Author: tamas
 *
 * Created on November 1, 2019, 7:10 AM
 */

#ifndef _MAIN_H
#define _MAIN_H

#include "ui_Main.h"

class Main : public QDialog {
    Q_OBJECT
public:
    Main();
    virtual ~Main();
private:
    Ui::Main widget;
};

#endif /* _MAIN_H */
