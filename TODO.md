### 2021
- [ ] Speed up UTF-8 decoder (using pre-computed tables/SIMD)
  - [IBM paper on SIMD speedup of UTF-8 decode algorithm](https://researcher.watson.ibm.com/researcher/files/jp-INOUEHRS/IPSJPRO2008_SIMDdecoding.pdf)
  - [C example of fast UTF-8 decoder](https://gist.github.com/gorb314/7888804)
  - [Article on writing a SSE4 UTF-8 to UTF-16 decoder](https://woboq.com/blog/utf-8-processing-using-simd.html)
- [x] Speed up `hz_segment_t` structure, try plain buffer rather than a doubly linked list.
- [ ] Write a proper pool allocator for internal allocations.
- [ ] Cache calls to `hz_shape`
- [ ] Add loading from UTF-16, Windows-1252 (CP1252), etc...
- [ ] Add support for Johab, UCS-2, UCS-4, UTF-16, UTF-32, [GB-18030](https://fr.wikipedia.org/wiki/GB_18030). etc...
- [ ] Write SSE4, AVX-2 and AVX-512 optimizations for UTF-8 decoding
and codepoint mapping.
- [ ] Write reliable fast endianness check function, possibly look into compile time endianness checks.
- [ ] Write fast unpack array functions which take into account byte swapping if necessary (SIMD).

### 6/3/2022
- [ ] Look for a different hash function for `hz_map_t` such as MurmurHash3 or MeowHash, 
make it resizable, make it generic and improve performance.
- [ ] Lower memory footprint of `hz_range_list_t` and improve its initialization speed.