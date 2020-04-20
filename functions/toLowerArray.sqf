//Converts all string elements of an array to lwoercase text
params["_inputArray"];

{
	//_inputArray select _x
	_inputArray set [_forEachIndex, toLower(_inputArray select _forEachIndex)];
} forEach _inputArray;

_inputArray