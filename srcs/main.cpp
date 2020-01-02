#include "npuzzle.hpp"
#include "Puzzle.hpp"
using namespace std;

int main(int ac, char **av)
{
	PUZZLE board{{ 3, 2, 6 },
					{ 1, 4, 0 },
					{ 8, 7, 5 }};

    Puzzle& puzzle = Puzzle::getInstance();

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