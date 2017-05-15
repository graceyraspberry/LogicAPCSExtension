/*
 * TruthTable.cpp
 *
 *  Created on: May 15, 2017
 *      Author: human
 */

#include "TruthTable.h"

/**
 * @param length the size that truthtable will be initialized to
 */
TruthTable::TruthTable(int length) {
	truthtable_ = new bool[length];
}

/**
 * Mutator for ease of use in testing
 * @param arr the boolean values to be assigned to the truthtable
 */
void TruthTable::setTruthTable(bool arr[]) {
	truthtable_ = arr;
}

/**
 * Returns a boolean array as a truth table for conducting propositional analysis with the "and" propositional constant
 * @param a the boolean array of possible values for the first propositional constant
 * @param b the boolean array of possible values for the second propositional constant
 */
void TruthTable::evaluateAnd(bool a[], bool b[]) {
	for (int i = 0; i < sizeof(a); i++) {
		if (a[i] && b[i]) {
			truthtable_[i] = true;
		} else {
			truthtable_[i] = false;
		}
	}
}

/**
 * Evaluates and propagates a truth table of values after evaluating the values in "or" operator sentence
 * @param a the boolean array of possible values for the first propositional constant
 * @param b the boolean array of possible values for the second propositional constant
 */
void TruthTable::evaluateOr(bool a[], bool b[]) {
	for (int i = 0; i < sizeof(a); i++) {
		if (a[i] || b[i]) {
			truthtable_[i] = true;
		} else {
			truthtable_[i] = false;
		}
	}
}

/**
 * Evaluates the possible truth values of the negation statement
 * @param a the boolean array of the values of the propositional constant being negated
 */
void TruthTable::evaluateNegate(bool a[]) {
	for (int i = 0; i < sizeof(a); i++) {
		if (!a[i]) {
			truthtable_[i] = true;
		} else {
			truthtable_[i] = false;
		}
	}
}

/**
 * Evaluates and propagates a truth table of the value of an implication sentence
 * @param a the values of the first propositional constant
 * @param b the values of the second propositional constant
 */
void TruthTable::evaluateImply(bool a[], bool b[]) {
	for (int i = 0; i < sizeof(a); i++) {
		if (a[i] && !b[i]) {
			truthtable_[i] = false;
		} else {
			truthtable_[i] = true;
		}
	}
}

/**
 * Evaluates and propagates a truth table of the values from a biconditional sentence
 * @param a the values of the first propositional constant
 * @param b the values of the second propositional constant
 */
void TruthTable::evaluateBiconditional(bool a[], bool b[]) {
	for (int i = 0; i < sizeof(a); i++) {
		if (a[i] == b[i]) {
			truthtable_[i] = true;
		} else {
			truthtable_[i] = false;
		}
	}
}

/**
 * Evaluates the equivalence between truthTable and otherTruthTable
 * @param otherTruthTable the set of truth values for a logical sentence
 * @return true when otherTruthTable iff every assignment that satisfies otherTruthTable also satisfies TruthTable
 */
bool TruthTable::equivalent(bool otherTruthTable[]) {
	bool equivalent = true;
	for (int i = 0; i < sizeof(otherTruthTable); i++) {
		if ((otherTruthTable[i] && !truthtable_[i])
				|| (!otherTruthTable[i] && truthtable_[i])) {
			truthtable_[i] = true;
		} else {
			truthtable_[i] = false;
		}
	}
	return equivalent;
}

/**
 * Returns logical entailment of the truthtable and the boolean[] otherTruthTable
 * @param otherTruthTable the set of truth values in which truthTable will be evaluated against for entailment
 * @return true if every truth assignment that satisfies truthtable also satisfies "a"
 */
bool TruthTable::entails(bool otherTruthTable[]) {
	bool entails = true;
	for (int i = 0; i < sizeof(otherTruthTable); i++) {
		if (truthtable_[i] && !otherTruthTable[i])
			entails = false;
	}
	return entails;
}

/**
 * Evaluates logical consistency between "a" and the values in truthtable
 * @param otherTruthTable the set of truth values
 * @return true iff there is a truth assignment that satisfies both "otherTruthTable" and truthtable
 */
bool TruthTable::consistent(bool otherTruthTable[]) {
	bool consistent = false;
	for (int i = 0; i < sizeof(otherTruthTable); i++) {
		if (truthtable_[i] && otherTruthTable[i])
			consistent = true;
	}
	return consistent;
}

/**
 * Returns the logical property of validity of the statement based on the truth table values in truthtable
 * @return true if the sentence if it is satisfied by every truth assignment
 */
bool TruthTable::valid() {
	bool valid = true;
	for (bool a : truthtable_) {
		if (!a)
			valid = false;
	}
	return valid;
}

/**
 * Returns the logical property of unsatisfiablity of the statement by examining the truthtable
 * @return true iff it is not satisfied by any truth assignment
 */
bool TruthTable::unsatisfiable() {
	bool unsatisfiable = true;
	for (bool a : truthtable_) {
		if (a)
			unsatisfiable = false;
	}
	return unsatisfiable;
}

/**
 * Returns the logical property of unsatisfiability of the statement based on the truth table
 * @return true iff there is some truth assignment that satisfies it and some truth assignment that falsifies
 */
bool TruthTable::contingent() {
	bool tpresent = false; //is there a true present
	bool fpresent = false; //is there a false present
	for (bool a : truthtable_) {
		if (a)
			tpresent = true;
		if (!a)
			fpresent = true;
	}
	if (tpresent && fpresent) {
		return true;
	} else {
		return false;
	}
}

TruthTable::~TruthTable() {

}

