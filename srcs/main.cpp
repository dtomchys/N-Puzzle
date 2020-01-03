#include "npuzzle.hpp"
#include "Puzzle.hpp"
using namespace std;

int main(int ac, char **av)
{
    Puzzle& puzzle = Puzzle::getInstance();
    puzzle.solve();

	//      for(int y=0;y<puzzle.size();++y)
    // {
    //     for(int x=0;x<puzzle[y].size();++x)
    //     {
    //         cout<<puzzle[y][x]<<ends;
    //     }
    //     cout<<endl;
    // }

	return 0;
}