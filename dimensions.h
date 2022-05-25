#ifndef DIMENSIONS_H
#define DIMENSIONS_H
extern float cube_unit;

extern float lightx;
extern float lighty;
extern float lightz;

extern float tableX;
extern float tableY;
extern float tableZ;

extern float EmployeeTableX;
extern float EmployeeTableY;
extern float EmployeeTableZ;

extern float HeadTableX;
extern float HeadTableY;
extern float HeadTableZ;

extern float chairX;
extern float chairY;
extern float chairZ;

extern float tablechairX;
extern float tablechairY;
extern float tablechairZ;

extern float EmployeeTableChairX;
extern float EmployeeTableChairY;
extern float EmployeeTableChairZ;

extern float diningTableX;
extern float diningTableY;
extern float diningTableZ;

extern float filingCabinetUnitx;
extern float filingCabinetUnity;
extern float filingCabinetUnitz;

extern float FileCabinetdrawerOpen;

extern float FileCabinetsingleDrawerOpen;

extern float planksInBench;

extern float gapInPieces;

extern float parkBenchx;
extern float parkBenchz;

extern float cabinetx;
extern float cabinety;
extern float cabinetz;

extern float bedX;
extern float bedZ;

extern float lampY;

extern float lampWidth;

extern float lampHandlex;
extern float lampHandley;

extern float lampRadious;

extern float numberOfLamps;

extern float pathX;

extern float footpathX;

extern float roadX;

extern float roomX;
extern float roomY;
extern float roomZ;

extern float stairWidth;

extern float floorz;
extern float floorx;
extern float floory;

extern float officeFloorx;
extern float officeFloory;
extern float officeFloorz;

extern float stairHeight;

extern float groundx;
extern float groundy;
extern float groundz;

extern float doorHeight;
extern float doorWidth;

extern float grillHeight;
extern float grillWidth;

extern const int L;

//extern GLfloat *controlpoints[L+1];
extern int totalVasePoints;

extern const int totalLegPoints;

extern const int totalToolTopPoints;

extern const int totalChairBackPoints1;

extern const int totalChairHandlePoints;

extern const int totalDeskTopPoints;

extern const int totalPillowPoints;

extern const int totalBulbPoints;
//extern GLfloat *vasePoints[];
extern float wcsClkDn[];
extern float wcsClkUp[];
//class point1
//{
//public:
//    point1()
//    {
//        x=0;
//        y=0;
//    }
//    int x;
//    int y;
//} clkpt[2];
extern int flag;
extern int clikd;
extern const int nt;
extern const int ntheta;
extern GLint viewport[]; //var to hold the viewport info
extern GLdouble modelview[]; //var to hold the modelview info
extern GLdouble projection[]; //var to hold the projection matrix info

extern int totalPoints;
extern vector<vector<GLfloat> >newPoints;

#endif // DIMENSIONS_H
