#ifndef FURNITURES_H
#define FURNITURES_H

void DrawerKnob();

void TableDrawer(float plateX, float plateY, float plateZ, float sideX, float sideY, float sideZ,int texture=24);

void Table(bool drawer=false);

void TableRotate(float angle);

void Chair();

void ChairRotate(float angle);

void TableChair();

void TableChairRotate(float angle);

void EmployeeTableChair(float angle);

void HeadTable();

void HeadTableChair();

void DiningTable();

void Tool();

void DiningTableAndTools();

void OfficeChair();

void Desk();

void DeskAndChair(float angle=0);

void DeskAndChairRotate(float angle);

void EmployeeTable(bool drawer=false);

void FilingCabinet(int row=2, int column=1, float angle=0);

void FilingCabinetRotate(int row, int column, float angle=0);

void ShortCabinet(int row=2, int column=1);

void ParkBench();

void ParkBenchPair();

void Cabinet(bool drawer=false);

void CabinetInverse(bool drawer=false);

void Pillow();

void PillowPair(float gap);

void Bed(float bedWall, float pillowx, float pillowy, float pillowz);

void CeilingFan();

void axes();

void FlowerVase(float red=1, float green=1, float blue=1, float alpha=1);

void manualCurve();

#endif // FURNITURES_H
