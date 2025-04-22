#include<iostream>
#include "Game.h"
Game::Game() {
    cout <<"**************" << endl << "* Play Keno! *" <<endl<< "**************" << endl;
    playGame();
}
void Game:: printMatches(std::vector<int>playerPicks,std::vector<int>kenoNumbers) {
    //cout << playerPicks[3];
    //cout << kenoNumbers[3];
    cout << "You matched: ";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (playerPicks[i] == kenoNumbers[j]) {
                cout << playerPicks[i] << " ";
                m_matches.push_back(playerPicks[i]);
            }
        }

    }
    cout << endl;

}
void Game::displayResults() {
    cout << "Matching " << m_matches.size()<< " of 20 numbers wins $";

    if( m_matches.size() == 10 ) {
        cout << "25,000" << endl;
    } else if( m_matches.size() == 9 ) {
        cout << "2,500" << endl;
    }else if( m_matches.size() == 8 ) {
        cout << "250" << endl;
    }else if( m_matches.size() == 7 ) {
        cout << "50" << endl;
    }else if( m_matches.size() == 6 ) {
        cout << "10" << endl;
    }else if( m_matches.size() == 5 ) {
        cout << "5" << endl;
    }else {
        cout << "0" << endl;
    }
    /*10 of 20 $25,000
 9 of 20 $2,500
 8 of 20 $250
 7 of 20 $50
 6 of 20 $10
 5 of 20 $5
less than 5 $0*/
}
void Game::playGame() {
    char playAgain ='y';
    while (playAgain =='y') {
        m_player.inputPlayerNumbers();
        cout << "----------------------------------Results----------------------------------" << endl;
        cout << "Keno Numbers: ";
        m_keno.generateNumbers();
        m_keno.printKenoNumbers();
        cout << "Player Picks: ";
        m_player.printPlayerNumbers();
        //5 22 36 43 48 50 60 64 65 78
        printMatches(m_player.getPlayerNumbers(),m_keno.getKenoNumbers());
        displayResults();
        m_matches.clear();
        m_player.clearPlayerNumbers();
        m_keno.clearKenoNumbers();
        cout << endl;
        cout <<"Play again? (y/n): ";
        cin>> playAgain;
    }
    cout << endl;
    cout <<"THANKS FOR PLAYING!!";
}
