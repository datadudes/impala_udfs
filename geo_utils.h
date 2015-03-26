#ifndef IMPALA_UDF_SAMPLE_UDF_H
#define IMPALA_UDF_SAMPLE_UDF_H

#include "udf/udf.h"

using namespace impala_udf;

DoubleVal Distance(FunctionContext* context, const DoubleVal& lat1, const DoubleVal& long1, const DoubleVal lat2, const DoubleVal long2);

#endif