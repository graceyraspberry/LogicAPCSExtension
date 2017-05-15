/*
 * TruthTable.h
 *
 *  Created on: May 15, 2017
 *      Author: human
 */

#ifndef TRUTHTABLE_H_
#define TRUTHTABLE_H_

class TruthTable {
public:
	TruthTable(int length);

	void setTruthTable(bool arr[]);
	void evaluateAnd(bool a[], bool b[]);
	void evaluateOr(bool a[], bool b[]);
	void evaluateNegate(bool a[]);
	void evaluateImply(bool a[], bool b[]);
	void evaluateBiconditional(bool a[], bool b[]);

	bool equivalent(bool otherTruthTable[]);
	bool entails(bool otherTruthTable[]);
	bool consistent(bool otherTruthTable[]);

	bool valid();
	bool unsatisfiable();
	bool contingent();

	virtual ~TruthTable();

private:
	bool* truthtable_[];
};

#endif /* TRUTHTABLE_H_ */
