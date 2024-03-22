/// @brief Musical Notes Application Programming Interface (API) Implementation File
/// CPSC-298-6 Programming in C++ Project Musical Note Frequencies with Functions
/// @author rrahman@chapman.edu

#include <iostream>
#include <string>
#include <cmath>
#include "MusicalNoteApi.h"


double computeFrequency(int nu, int k)
{
	double f = -1.0; 
	if (nu >= 0 && k >= 0 && k < k_nHalfTonesInOctave){
		f = k_dFrequencyRef * pow(2.0, nu + k / 12.0);
	}
	else
	{
		std::cerr << "ERROR: computeFrequency preconditions not satisfied; dFrequencyHz nu (" << nu << ") or k (" << k << ") invalid" << std::endl;
	}

	return f;
}

double computeWavelengthInCm(double dFrequencyHz)
{

	double dWavelengthCm = -1.0; 
	if ((dFrequencyHz < 0.0) || (!std::isfinite(dFrequencyHz)) || (FP_ZERO == std::fpclassify(dFrequencyHz)))
	{
		dWavelengthCm = -1.0; // Indicate Error
		std::cerr << "ERROR: computeWavelengthInCm preconditions not satisfied; dFrequencyHz invalid: " << dFrequencyHz << std::endl;
	}
	else {
		dWavelengthCm = (k_dSpeedOfSoundCmPerSecond / dFrequencyHz);
	}

	return dWavelengthCm;
}

const std::string getNoteName(int nu, int k){
	const static std::string a_strNotePrefix[] = {
			"C", "C#", "D","D#", "E", "F", "F#", "G", "G#", "A", "A#", "B",
	};

	std::string strNote = "UNK";

	if ((k >= 0) && (k < k_nHalfTonesInOctave) && (nu >= 0))
	{
		strNote = a_strNotePrefix[k] + std::to_string(nu);
	}

	return strNote; 
}

int main(){
	int nOctaves = 11; 

	for (int nu = 0; nu < nOctaves; nu++)
	{
		for (int k = 0; k < k_nHalfTonesInOctave; k++)
		{
			// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //
			// TODO: Call your function to compute the frequency in Hertz of the note corresponding to 
			//       octave nu and half-tone k and assign it to a variable named f of the appropriate type.
			// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //

			// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //
			// TODO: Call your function to compute the wavelength of the note given its frequency in Hertz
			//       and assign it to a variable named dWavelengthCentimeters of the appropriate type.
			// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //

			// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //
			// TODO: Call function getNoteName to obtain the name of the note as a string variable and
			//       assign it to a variable named strNote of the appropriate type. 
			// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //

			double f = computeFrequency(nu, k);
			double dWavelengthCentimeters = computeWavelengthInCm(f);

			std::string strNote = getNoteName(nu, k);


			std::cout << "Note: " << strNote << "; nu: " << nu << "; k: " << k << "; frequency: " << f << " Hz; wavelength: " << dWavelengthCentimeters << " cm" << std::endl;

		}
	}

	std::cout << std::endl << std::endl;
	std::cout << "------------------------------------------------ CHECK ERROR HANDLING ---------------------------------------------------------------" << std::endl;

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //
	// TODO: Call your function to compute the frequency in Hertz of the note corresponding to 
	//       octave nu and half-tone k and assign it to a variable named f of the appropriate type.
	//       Pass -1 as the value for argument nu and -1 for the value for arugment k. 
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //
	// TODO: Call your function to compute the wavelength of the note given its frequency in Hertz
	//       and assign it to a variable named dWavelengthCentimeters of the appropriate type.
	//       Pass -16.35 as the value for the argument dFrequencyHz. 
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //
	// TODO: Call function getNoteName to obtain the name of the note as a string variable and
	//       assign it to a variable named strNote of the appropriate type. 
	//       Pass -1 as the value for argument nu and -1 for the value for arugment k. 
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ //

	double f = computeFrequency(-1, -1);
	double dWavelengthCentimeters = computeWavelengthInCm(-16.35);

	std::string strNote = getNoteName(-1, -1);

	
	std::cout << "Note: " << strNote << "; nu: -1; k: -1; frequency: " << f << " Hz; wavelength: " << dWavelengthCentimeters << " cm" << std::endl;

	return 0;
}
