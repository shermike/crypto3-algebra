//---------------------------------------------------------------------------//
// Copyright (c) 2020 Mikhail Komarov <nemo@nil.foundation>
// Copyright (c) 2020 Nikita Kaskov <nbering@nil.foundation>
// Copyright (c) 2020 Ilias Khairullin <ilias@nil.foundation>
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

#ifndef CRYPTO3_ALGEBRA_CURVES_ALT_BN128_HPP
#define CRYPTO3_ALGEBRA_CURVES_ALT_BN128_HPP

#include <nil/crypto3/algebra/curves/detail/alt_bn128/basic_policy.hpp>
#include <nil/crypto3/algebra/curves/detail/alt_bn128/g1.hpp>
#include <nil/crypto3/algebra/curves/detail/alt_bn128/g2.hpp>

//#include <nil/crypto3/algebra/pairing/alt_bn128.hpp>

namespace nil {
    namespace crypto3 {
        namespace algebra {
            namespace curves {

                using namespace algebra;

                template<std::size_t ModulusBits = 254, std::size_t GeneratorBits = CHAR_BIT>
                struct alt_bn128 {

                    using policy_type = detail::alt_bn128_basic_policy<ModulusBits, GeneratorBits>;

                    typedef typename policy_type::base_field_type base_field_type;
                    typedef typename policy_type::scalar_field_type scalar_field_type;
                    typedef typename policy_type::number_type number_type;
                    typedef typename policy_type::extended_number_type extended_number_type;

                    constexpr static const std::size_t base_field_bits = policy_type::base_field_bits;
                    constexpr static const number_type p = policy_type::p;

                    constexpr static const std::size_t scalar_field_bits = policy_type::scalar_field_bits;
                    constexpr static const number_type q = policy_type::q;

                    typedef typename detail::alt_bn128_g1<base_field_bits, CHAR_BIT> g1_type;
                    typedef typename detail::alt_bn128_g2<base_field_bits, CHAR_BIT> g2_type;

                    // typedef typename pairing::pairing_policy<alt_bn128<ModulusBits, GeneratorBits>> pairing_policy;

                    typedef typename policy_type::gt_field_type::value_type gt_type;

                    typedef std::vector<g1_type> g1_vector;
                    typedef std::vector<g2_type> g2_vector;
                };

                template<std::size_t ModulusBits = 254, std::size_t GeneratorBits = CHAR_BIT>
                using alt_bn128_g1 = typename alt_bn128<ModulusBits, GeneratorBits>::g1_type;

                template<std::size_t ModulusBits = 254, std::size_t GeneratorBits = CHAR_BIT>
                using alt_bn128_g2 = typename alt_bn128<ModulusBits, GeneratorBits>::g2_type;

                template<std::size_t ModulusBits = 254, std::size_t GeneratorBits = CHAR_BIT>
                using alt_bn128_gt = typename alt_bn128<ModulusBits, GeneratorBits>::gt_type;

            }    // namespace curves
        }        // namespace algebra
    }            // namespace crypto3
}    // namespace nil

#endif    // ALGEBRA_CURVES_ALT_BN128_HPP
