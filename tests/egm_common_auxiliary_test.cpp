/***********************************************************************************************************************
 *
 * Copyright (c) 2020, ABB Schweiz AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that
 * the following conditions are met:
 *
 *    * Redistributions of source code must retain the
 *      above copyright notice, this list of conditions
 *      and the following disclaimer.
 *    * Redistributions in binary form must reproduce the
 *      above copyright notice, this list of conditions
 *      and the following disclaimer in the documentation
 *      and/or other materials provided with the
 *      distribution.
 *    * Neither the name of ABB nor the names of its
 *      contributors may be used to endorse or promote
 *      products derived from this software without
 *      specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ***********************************************************************************************************************
 */

#include <cstdlib>
#include <iostream>

#include "abb_libegm/egm_common_auxiliary.h"

#include <google/protobuf/text_format.h>

bool estimateVelocitiesTest()
{
  abb::egm::wrapper::Euler estimate;
  double sample_time = 0.001;
  abb::egm::wrapper::Euler previousEuler = abb::egm::wrapper::Euler::default_instance();
  previousEuler.set_x(0.0);
  previousEuler.set_y(0.0);
  previousEuler.set_z(0.0);
  abb::egm::wrapper::Quaternion previous;
  abb::egm::convert(&previous, previousEuler);
  abb::egm::wrapper::Euler currentEuler = abb::egm::wrapper::Euler::default_instance();
  currentEuler.set_x(0.01);
  currentEuler.set_y(0.01);
  currentEuler.set_z(0.01);
  abb::egm::wrapper::Quaternion current;
  abb::egm::convert(&current, currentEuler);
  abb::egm::estimateVelocities(&estimate, current, previous, sample_time);
  double eps = 1e-8;
  if (std::abs(9.9991272465327938 - estimate.x()) > eps)
  {
    return false;
  }
  if (std::abs(10.000872575773712 - estimate.y()) > eps)
  {
      return false;
  }
  if (std::abs(9.9991272465327938 - estimate.z()) > eps)
  {
      return false;
  }
  return true;
}

int main()
{
  if (!estimateVelocitiesTest())
  {
    std::cerr << "estimateVelocitiesTest FAILED" << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}