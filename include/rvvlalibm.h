/*******************************************************************************
* This file is part of rvvlalibm (https://github.com/metalibm/rvvlalibm)
*******************************************************************************
* MIT License
*
* Copyright (c) 2022 Nicolas Brunie
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*******************************************************************************
* created:              Jan  9th, 2022
* last-modified:        Jan  9th, 2022
*
* author(s):    Nicolas Brunie (metalibm POINT dev AT gmail com)
******************************************************************************/
void vla_exp_single(double* dst, double* src, uint32_t vector_len);

void vla_exp_double(double* dst, double* src, uint32_t vector_len);

void vla_exp2_single(float* dst, float* src, uint32_t vector_len);

void vla_exp2_double(double* dst, double* src, uint32_t vector_len);

void vla_log_single(double* dst, double* src, uint32_t vector_len);

void vla_log_double(double* dst, double* src, uint32_t vector_len);

void vla_log2_single(float* dst, float* src, uint32_t vector_len);

void vla_log2_double(double* dst, double* src, uint32_t vector_len);

void vla_log10_single(float* dst, float* src, uint32_t vector_len);

void vla_log10_double(double* dst, double* src, uint32_t vector_len);
