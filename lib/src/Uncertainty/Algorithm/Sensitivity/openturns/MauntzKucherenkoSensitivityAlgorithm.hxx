//                                               -*- C++ -*-
/**
 *  @brief Implementation for sensitivity algorithms
 *
 *  Copyright 2005-2017 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_MAUNTZKUCHERENKOSENSITIVITYALGORITHM_HXX
#define OPENTURNS_MAUNTZKUCHERENKOSENSITIVITYALGORITHM_HXX

#include "openturns/SobolIndicesAlgorithmImplementation.hxx"

BEGIN_NAMESPACE_OPENTURNS



/**
 * @class MauntzKucherenkoSensitivityAlgorithm
 *
 */

class OT_API MauntzKucherenkoSensitivityAlgorithm
  : public SobolIndicesAlgorithmImplementation
{
  CLASSNAME;
public:

  /** Default constructor */
  MauntzKucherenkoSensitivityAlgorithm();

  /** Constructor with parameters */
  MauntzKucherenkoSensitivityAlgorithm(const Sample & inputDesign,
                                       const Sample & outputDesign,
                                       const UnsignedInteger size);

  /** Constructor with distribution / model parameters */
  MauntzKucherenkoSensitivityAlgorithm(const Distribution & distribution,
                                       const UnsignedInteger size,
                                       const Function & model,
                                       const Bool computeSecondOrder = true);

  /** Constructor with experiment / model parameters */
  MauntzKucherenkoSensitivityAlgorithm(const WeightedExperiment & experiment,
                                       const Function & model,
                                       const Bool computeSecondOrder = true);

  /** Virtual constructor */
  virtual MauntzKucherenkoSensitivityAlgorithm * clone() const;

  /** String converter */
  virtual String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  virtual void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  virtual void load(Advocate & adv);

protected:

  /** Internal method that compute Vi/VTi using a huge sample */
  Sample computeIndices(const Sample & sample,
                        Sample & VTi) const;

}; /* class MauntzKucherenkoSensitivityAlgorithm */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_MAUNTZKUCHERENKOSENSITIVITYALGORITHM_HXX */
