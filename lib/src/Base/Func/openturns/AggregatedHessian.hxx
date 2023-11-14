//                                               -*- C++ -*-
/**
 *  @brief The hessian part of linear combination of polynomials
 *
 *  Copyright 2005-2024 Airbus-EDF-IMACS-ONERA-Phimeca
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
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_AGGREGATEDHESSIAN_HXX
#define OPENTURNS_AGGREGATEDHESSIAN_HXX

#include "openturns/HessianImplementation.hxx"
#include "openturns/AggregatedEvaluation.hxx"

BEGIN_NAMESPACE_OPENTURNS



/**
 * @class AggregatedHessian
 *
 * The hessian part of linear combination of polynomials
 */

class OT_API AggregatedHessian
  : public HessianImplementation
{
  CLASSNAME
public:
  /** Default constructor */
  AggregatedHessian();

  /** Parameters constructor */
  explicit AggregatedHessian(const AggregatedEvaluation & evaluation);

#ifndef SWIG
  /** Parameters constructor */
  explicit AggregatedHessian(const Pointer<AggregatedEvaluation> & p_evaluation);
#endif

  /** Virtual constructor */
  AggregatedHessian * clone() const override;

  /** Hessian method */
  SymmetricTensor hessian(const Point & inP) const override;

  /** Accessor for input point dimension */
  UnsignedInteger getInputDimension() const override;

  /** Accessor for output point dimension */
  UnsignedInteger getOutputDimension() const override;

  /** String converter */
  String __repr__() const override;
  String __str__(const String & offset = "") const override;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const override;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv) override;


protected:

private:
  /** The associated evaluation */
  Pointer<AggregatedEvaluation> p_evaluation_;

} ; /* class AggregatedHessian */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_AGGREGATEDHESSIAN_HXX */
