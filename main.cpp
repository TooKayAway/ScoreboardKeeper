#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

void printScoreboard(vector < vector<int> > input ){
    cout<<"SCOREBOARD"<<endl;
    for ( int row = 0; row < input.size(); row++ ) {
        cout<<"Player "<<row + 1<<": ";
        for ( int col = 0; col < input[row].size(); col++ ) {
            cout<<input[row][col]<<"|";
        }
        cout<<endl;
    }
}

int randomBetween(int first, int second ) {
    if ( first > second ) {
        return second + rand()%(first-second+1);
    } else {
        return first + rand()%(second-first+1);
    }
}

int main()
{
  srand((int) time(0));
  int periods;
  int teams;

  cout<<"How many competitors? ";
  cin>>teams;
  cout<<"How many scoring periods? ";
  cin>>periods;

  if( teams < MIN_TEAMS || periods < MIN_PERIODS || 
      teams > MAX_TEAMS || periods > MAX_PERIODS )
  {
    cout<<"Must have between "<<MIN_TEAMS<<" and "<<MAX_TEAMS<<" competitors.\n";
    cout<<"and between "<<MIN_PERIODS<<" and "<<MAX_PERIODS<<" periods.\n";
    return 0;
  }
  else
  {
   //make scoreboard and fill it with zeros
    vector < vector <int> > scoreboard;
    scoreboard.resize( teams );
    for ( int row = 0; row < scoreboard.size(); row++ ) {
        scoreboard[row].resize( periods );
    }

    for ( int row = 0; row < scoreboard.size(); row++ ) {
        for ( int col = 0; col < scoreboard[row].size(); col++ ) {
            scoreboard[row][col] = 0;
        }
    }
    printScoreboard(scoreboard);
    
    for ( int row = 0; row < scoreboard.size(); row++ ) {
        for ( int col = 0; col < scoreboard[row].size(); col++ ) {
            scoreboard[row][col] = randomBetween(5,5);
        }
    }
    printScoreboard(scoreboard);
  }
  return 0;
}
