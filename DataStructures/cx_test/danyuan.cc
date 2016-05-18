#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

const int MAXINT = 32767;// Positive infinite
const int MAXNUM = 10;
int dist[MAXNUM];
int preva[MAXNUM];

// Scenic Spot Class define
class SS_Node //scenic spot class store data
{
public:
    SS_Node() {};

    // ~SS_Node();
    bool getInformation();
    std::string getName() { return Name; }

    std::string Number;// Store scenic spot number
    std::string Name;// Store scenic spot name
    std::string Introduction;// Store scenic spot introduction
};

bool SS_Node::getInformation() {
    std::cout << "Please input information: " << std::endl
        << "Scenic Spot number? ";
    std::string _number;
    std::cin >> _number;

    std::string _name;
    std::cout << "Scenic Spot Name? ";
    std::cin >> _name;

    std::string _introduction;
    std::cout << "Scenic Spot introduction? ";
    std::cin >> _introduction;

    Number = _number;
    Name = _name;
    Introduction = _introduction;

    return true;
}

// School Class define
class School
{
public:
    School();
    School(SS_Node*, Matrix);
    //~School();

    SS_Node *Scenic_Spot;// store Scenic Spot 
    Matrix School_road;// store School road

};

School::School() {
    School_road.resize(MAXNUM, MAXNUM);
}
School::School(SS_Node *Scenic, Matrix road) {
    Scenic_Spot = Scenic;
}

// Function define
Matrix getFigure();
void outputLine(std::string, std::string, std::string);
SS_Node* readSpot();
Matrix Dijkstra(Matrix, int);
void displayMatrix(Matrix);


int main() {
    School test;
    for (int i = 0; i < MAXNUM; ++i)
        for (int j = 0; j < MAXNUM; ++j) {
            if(i != j)
                test.School_road[i][j] = 32767;
        }
    
    // getFigure can use or not.
    //test.School_road = getFigure();
    test.Scenic_Spot = readSpot();

    // 下面是一组测试数据
    test.School_road[0][1] = 2;
    test.School_road[0][2] = 4;
    test.School_road[0][3] = 1;

    test.School_road[1][0] = 2;
    test.School_road[1][2] = 3;
    test.School_road[1][3] = 32767;

    test.School_road[2][0] = 4;
    test.School_road[2][1] = 3;
    test.School_road[2][3] = 6;

    test.School_road[3][0] = 1;
    test.School_road[3][1] = 32767;
    test.School_road[3][2] = 6;

    displayMatrix(test.School_road);

    std::cout << "All Scenic Spot is:" << std::endl;
    for (int i = 0;i < MAXNUM; ++i) {
        std::cout << left << setw(5) << test.Scenic_Spot[i].Number << setw(30)
            << test.Scenic_Spot[i].Name << setw(30) << test.Scenic_Spot[i].Introduction
            << std::endl;
    }
    
    int flag_Query = 0;
    while (flag_Query == 0) {
        std::cout << std::endl << "Information Query (using node number)" << std::endl
            << "Node_Number? ";
        int temp_node_number;
        cin >> temp_node_number;
        std::cout << left << setw(5) << test.Scenic_Spot[temp_node_number].Number << setw(30)
            << test.Scenic_Spot[temp_node_number].Name << setw(30) << test.Scenic_Spot[temp_node_number].Introduction
            << std::endl;
        std::cout << std::endl << std::endl;
        
        std::cout << "Query again?('0' for next, '1' for exit)" 
            << std::endl << "?";
        cin >> flag_Query;
    }

    int flag = 0;
    while (flag == 0) {
        std::cout << "Please enter the start node number: " << std::endl
            << "?";
        int startNum;
        std::cin >> startNum;

        std::cout << "Please enter the reach node number: " << std::endl
            << "?";
        int reachNum;
        std::cin >> reachNum;

        Dijkstra(test.School_road, startNum);
        std::cout << "The road length is: " << dist[reachNum] << std::endl;

        int j = reachNum;
        std::cout << startNum << "---";
        while (1) {         
            std::cout << preva[j] << "---";
            j = preva[j];
            if (preva[j] == startNum)
                break;
        }
        cout << reachNum;


        // std::cout << "The road is: " << std::endl;
        // for (; j >= 0; --j) {
        //  std::cout << tempStore[j] << "---";
        // }

        std::cout << std::endl;
        std::cout << "Continue enter 0,Exit enter 1:" << std::endl
            << "?";
        std::cin >> flag;
    }

    return 0;
}


Matrix getFigure() {
    int nodeNumber = MAXNUM;

    Matrix newFigure(nodeNumber, nodeNumber);// A new figure to store the road

    int flag = 0;// using in "while", judging whether input or not
    while (flag == 0) {
        char temp[5];// Store node data
        int length = 0;// Store road length
        cout << "Enter the two node, example(<1,2>)" << endl
            << "?";// enter the two node (if two node linked)
        cin >> temp;

        cout << "Enter the road length: " << endl
            << "?";
        cin >> length;

        int temp1 = (int)(temp[1] - '0');
        int temp2 = (int)(temp[3] - '0');

        newFigure[temp1][temp2] = length;// store length
        newFigure[temp2][temp1] = length;// store length        

        cout << "Do you want enter new? (enter 0 for next, enter 1 for exit)" << endl
            << "?";
        cin >> flag;
    }

    return newFigure;
}

SS_Node* readSpot() {
    std::string fn;
    std::cout << "In put file name : ";
    std::cin >> fn;
    std::ifstream inClientFile(fn, std::ios::in);

    // Exit program if ifstream could not open file
    if (!inClientFile) {
        std::cerr << "File could not be opened" << std::endl;
        exit(1);
    }// End if

    else
        std::cout << "Open the File 'Scenic_Spot.data'" << std::endl << std::endl;

    SS_Node* Temp = new SS_Node[MAXNUM];
    int i = 0;
    while (!inClientFile.eof()) {
        std::string tempString;
        for (int j = 0; j < 3; ++j) {
            // Function getline  
            getline(inClientFile, tempString);

            switch (j) {
            case 0:Temp[i].Number = tempString;break;
            case 1:Temp[i].Name = tempString;break;
            case 2:Temp[i].Introduction = tempString;break;
            }
        }
        ++i;
    }

    return Temp;
}

void outputLine(std::string a, std::string b, std::string c) {
    std::cout << a << std::endl
        << b << std::endl
        << c << std::endl;
}

Matrix Dijkstra(Matrix temp, int v0) {
    int nodeNumber = temp.rows();
    bool* S = new bool[nodeNumber];

    for (int i = 0; i < nodeNumber; ++i) {
        dist[i] = temp[v0][i];
        S[i] = false;
        if (dist[i] == MAXINT)
            preva[i] = -1;
        else
            preva[i] = v0;
    }

    dist[v0] = 0;
    S[v0] = true;

    for (int i = 2; i <= nodeNumber; i++) {
        int mindist = MAXINT;
        int u = v0;
        for (int j = 0; j < nodeNumber; ++j)
            if ((!S[j]) && dist[j] < mindist) {
                u = j;
                mindist = dist[j];
            }

        S[u] = true;

        for (int j = 0; j < nodeNumber; j++) {
            if ((!S[j]) && temp[u][j] < MAXINT) {
                if (dist[u] + temp[u][j] < dist[j]) {
                    dist[j] = dist[u] + temp[u][j];
                    preva[j] = u;
                }
            }
        }
    }
    return temp;
}

void displayMatrix(Matrix temp) {
    for (int i = 0; i < temp.rows(); ++i) {
        for (int j = 0; j < temp.cols(); ++j) {
            std::cout << left << setw(8) << temp[i][j];
        }
        
        std::cout << std::endl;
    }

}