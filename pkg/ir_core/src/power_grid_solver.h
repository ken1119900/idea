#ifndef __IR_INTERFACE_POWER_GRID_SOLVER__
#define __IR_INTERFACE_POWER_GRID_SOLVER__
#include <vector>
#include <map>
#include "matrix/src/matrix.h"

namespace pgNs
{

class PowerGrid;

class PowerGridSolver
{
	public:
		
		PowerGridSolver( PowerGrid *pg ,bool onlyR , double stepSize = 1e-10);
		~PowerGridSolver();
		void solveOnlyR(bool onlyR);
        void setTimeStep(double t);
		
		bool solve();
		bool solve(matrixNs::Vector *current);
		PowerGrid *getPowerGrid(){return powerGrid;}
		int  matrixSize(){return matrixG->size();}
		
	private:
		
		void setInitialVoltage();
		void buildMatrixCG();
		
		bool onlyR_;

		matrixNs::Matrix *matrixG;
		matrixNs::Matrix *matrixC;
		matrixNs::Matrix *matrixLHS;
		matrixNs::Vector *voltage;
		
        double timeStep;
		PowerGrid *powerGrid;
		
		void linkRow();
		
		std::map<int , int> comIndexToRow;
		
};
};
#endif
