//
//  OCSExponentialCurvesTable.h
//  ExampleProject
//
//  Created by Adam Boulanger on 6/21/12.
//  Copyright (c) 2012 Hear For Yourself. All rights reserved.
//

#import "OCSFunctionTable.h"

/** Constructs functions from segments of exponential curves.
 
 Ordinate values, in odd-numbered parts of the array, must be nonzero and must be alike in sign.
 
 Length of segment, in even-numbered parts of the array,  cannot be negative, but a zero is 
 meaningful for specifying discontinuous waveforms. The sum n1 + n2 + .... will normally equal 
 size for fully specified functions. If the sum is smaller, the function locations not included 
 will be set to zero; if the sum is greater, only the first size locations will be stored.
 
 @warning *Unsupported Functions* 
 
 Skipping rescaling is achieved by using a negative value for the GenRoutine Type.
 
 Discrete-point linear interpolation implies an increase or decrease along a segment by equal 
 differences between adjacent locations; exponential interpolation implies that the progression 
 is by equal ratio. In both forms the interpolation from a to b is such as to assume that the 
 value b will be attained in the n + 1th location. For discontinuous functions, and for the 
 segment encompassing the end location, this value will not actually be reached, although it 
 may eventually appear as a result of final scaling.
 */
@interface OCSExponentialCurvesTable : OCSFunctionTable

/// Instantiates an exponential curves function table.
/// @param tableSize         Number of points in the table. Must be a power of 2 or power-of-2 plus 1.
/// @param valueLengthPairs  Values must be nonzero and must be alike in sign.
/// Lengths must be non-nagative and the sum should equal `tableSize`.
- (id)initWithSize:(int)tableSize valueLengthPairs:(OCSParamArray *)valueLengthPairs;

@end