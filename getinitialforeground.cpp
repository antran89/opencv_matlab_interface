/*
 * Copyright (C) 2015 An Tran.
 * This code is for research, please do not distribute it.
 *
 */


#include <mex.h>
#include <opencv2/core.hpp>
#include <opencv2/matlab/mxarray.hpp>
#include <opencv2/matlab/bridge.hpp>
#include <stdint.h>

using namespace cv;
using namespace std;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    int dims = 5;
    mxArray *cell_array_ptr = mxCreateCellMatrix(5, 1);

    mxArray *num_array = mxCreateNumericMatrix(1, dims, mxUINT8_CLASS, mxREAL);
    mxSetData( num_array, mxMalloc(dims*sizeof(uint8_t)) );
    uint8_t *num_data = (uint8_t*)mxGetData(num_array);
    for (int i = 0; i < dims; i++)
        num_data[i] = i;
    mxSetCell(cell_array_ptr, 0, num_array);

    Mat a = Mat::zeros(3, 3, CV_32F);
    matlab::MxArray arr = cv::bridge::Bridge::FromMat<float>(a);    // this line has errors
    //mxSetCell(cell_array_ptr, 1, arr.releaseOwnership());

    plhs[0] = cell_array_ptr;
}
