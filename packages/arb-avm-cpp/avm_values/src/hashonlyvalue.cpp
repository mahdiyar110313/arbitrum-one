/*
 * Copyright 2020, Offchain Labs, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <avm_values/hashonlyvalue.hpp>
#include <avm_values/tuple.hpp>
#include <bigint_utils.hpp>

HashOnly::HashOnly(const value& val) {
    hash = ::hash(val);
    size = ::getSize(val);
}

void HashOnly::marshal(std::vector<unsigned char>& buf) const {
    std::array<unsigned char, 32> tmpbuf;
    to_big_endian(hash, tmpbuf.begin());
    buf.insert(buf.end(), tmpbuf.begin(), tmpbuf.end());

    std::array<unsigned char, 32> tmpbuf2;
    to_big_endian(size, tmpbuf2.begin());
    buf.insert(buf.end(), tmpbuf2.begin(), tmpbuf2.end());
}
std::ostream& operator<<(std::ostream& os, const HashOnly& val) {
    os << "HashOnly(" << val.getHash() << ")";
    return os;
}
