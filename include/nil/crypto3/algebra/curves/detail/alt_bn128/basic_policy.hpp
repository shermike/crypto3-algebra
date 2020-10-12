//---------------------------------------------------------------------------//
// Copyright (c) 2020 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020 Nikita Kaskov <nbering@nil.foundation>
//
// MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//---------------------------------------------------------------------------//

#ifndef CRYPTO3_ALGEBRA_CURVES_ALT_BN128_BASIC_POLICY_HPP
#define CRYPTO3_ALGEBRA_CURVES_ALT_BN128_BASIC_POLICY_HPP

#include <nil/crypto3/algebra/fields/alt_bn128/base_field.hpp>
#include <nil/crypto3/algebra/fields/alt_bn128/scalar_field.hpp>

#include <nil/crypto3/algebra/fields/fp2.hpp>
#include <nil/crypto3/algebra/fields/fp12_2over3over2.hpp>

#include <nil/crypto3/algebra/detail/literals.hpp>

namespace nil {
    namespace crypto3 {
        namespace algebra {
            namespace curves {
                namespace detail {

                    using namespace algebra;

                    template<std::size_t ModulusBits = 254, std::size_t GeneratorBits = CHAR_BIT>
                    struct alt_bn128_basic_policy { };

                    template<>
                    struct alt_bn128_basic_policy<254, CHAR_BIT> {
                        constexpr static const std::size_t base_field_bits = 254;

                        typedef fields::alt_bn128_fq<base_field_bits, CHAR_BIT> g1_field_type;
                        using base_field_type = g1_field_type;
                        typedef typename fields::fp2<base_field_type> g2_field_type;
                        typedef typename fields::fp12_2over3over2<base_field_type> gt_field_type;

                        typedef typename base_field_type::modulus_type number_type;
                        typedef typename base_field_type::extended_modulus_type extended_number_type;

                        constexpr static const number_type base_field_modulus = base_field_type::modulus;

                        constexpr static const std::size_t scalar_field_bits = 254;
                        typedef fields::alt_bn128_fr<scalar_field_bits, CHAR_BIT> scalar_field_type;
                        constexpr static const number_type scalar_field_modulus = scalar_field_type::modulus;

                        constexpr static const number_type p = base_field_modulus;
                        constexpr static const number_type q = scalar_field_modulus;

                        constexpr static const number_type a = number_type(0x00);
                        constexpr static const number_type b = number_type(0x03);
                    };

                    constexpr typename alt_bn128_basic_policy<254, CHAR_BIT>::number_type const
                        alt_bn128_basic_policy<254, CHAR_BIT>::a;

                    constexpr typename alt_bn128_basic_policy<254, CHAR_BIT>::number_type const
                        alt_bn128_basic_policy<254, CHAR_BIT>::b;

                    constexpr typename std::size_t const alt_bn128_basic_policy<254, CHAR_BIT>::base_field_bits;

                    constexpr typename std::size_t const alt_bn128_basic_policy<254, CHAR_BIT>::scalar_field_bits;

                    constexpr typename alt_bn128_basic_policy<254, CHAR_BIT>::number_type const
                        alt_bn128_basic_policy<254, CHAR_BIT>::p;

                    constexpr typename alt_bn128_basic_policy<254, CHAR_BIT>::number_type const
                        alt_bn128_basic_policy<254, CHAR_BIT>::q;

                }    // namespace detail
            }        // namespace curves
        }            // namespace algebra
    }                // namespace crypto3
}    // namespace nil

#endif    // ALGEBRA_CURVES_ALT_BN128_BASIC_POLICY_HPP