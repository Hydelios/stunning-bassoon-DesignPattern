//
// Created by Hydelios on 2021/4/11.
//

#ifndef DESIGNPATTERN_FLYWEIGHT_H
#define DESIGNPATTERN_FLYWEIGHT_H

#include <iostream>
#include <vector>

using namespace std;

//Flyweight pattern
/*
 * 用享元模式。其定义为：运用共享技术有效地支持大量细粒度的对象。在围棋中，棋子就是大量细粒度的对象。其属性有内在的，比如颜色、形状等，也有外在的，
 比如在棋盘上的位置。内在的属性是可以共享的，区分在于外在属性。因此，可以这样设计，只需定义两个棋子的对象，一颗黑棋和一颗白棋，
 这两个对象含棋子的内在属性；棋子的外在属性，即在棋盘上的位置可以提取出来，存放在单独的容器中。相比之前的方案，现在容器中仅仅存放了位置属性，
 而原来则是棋子对象。显然，现在的方案大大减少了对于空间的需求.
 */
enum PieceColor {
    BLACK,
    WHITE
};

struct PiecePos {
    int x;
    int y;

    PiecePos(int x, int y) : x(x), y(y) {}
};

class Piece {
protected:
    PieceColor m_color;
public:
    Piece(PieceColor color) : m_color(color) {}

    ~Piece() {}

    virtual void Draw();
};

class BlackPiece : public Piece {
public:
    BlackPiece(PieceColor color) : Piece(color) {}

    void Draw() override { cout << "BLACK" << endl; }
};

class whitePiece : public Piece {
public:
    whitePiece(PieceColor color) : Piece(color) {}

    void Draw() override { cout << "WHITE" << endl; }
};

class ChessBroad {
private:
    vector<PiecePos> m_pos;
    string player_white;
    string player_black;
    Piece *m_black;//黑棋棋子
    Piece *m_white;//白棋棋子

public:
    ChessBroad(string white, string black) : player_white(white), player_black(black) {
        m_black = nullptr;
        m_white = nullptr;
    }

    ~ChessBroad() {}

    void SetPiece(PieceColor color, PiecePos pos) {
        if (color == BLACK) {
            if (m_black == nullptr)
                m_black = new BlackPiece(BLACK);//只new一颗黑棋
            m_black->Draw();
            cout << "x:" << pos.x << "y:" << pos.y << endl;
        } else {
            if (m_black == nullptr)
                m_black = new BlackPiece(WHITE);
            m_black->Draw();
            cout << "x:" << pos.x << "y:" << pos.y << endl;
        }
    }
};

#endif //DESIGNPATTERN_FLYWEIGHT_H