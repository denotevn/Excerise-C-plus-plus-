// deck.h by Bill Weinman <http://bw.org/>
// updated 2002-08-11

#ifndef deck_h
#define deck_h

#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "bwexception.h"

namespace BW {

typedef uint64_t uint64;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;

constexpr const char * suitstr = "cdhs";
constexpr const char * facecards = "ATJQK";
constexpr uint8 default_deck = 52;
constexpr uint8 max_decks = 10;
constexpr uint8 suitcount = 4;
constexpr uint8 rankcount = 13;

typedef struct {
    uint8 suit : 4;
    uint8 rank : 4;
} Card;

class Deck {
    uint8 _cards_per_deck = 0;
    uint8 _numdecks = 0;
    uint16 _remaining_count = 0;
    Card * _deck = nullptr;

    void _init_deck();
    void _delete_deck();
    void _create_deck();
    void _init();

    Deck(const Deck &); // disallow copy ctor
    Deck & operator = (Deck); // disallow assignment operator
public:
    Deck() : _cards_per_deck(default_deck), _numdecks(1) { _init(); }
    Deck(uint8 n) : _cards_per_deck(default_deck), _numdecks(n) { _init(); }
    Deck(Deck &&) noexcept; // move ctor
    ~Deck();
    
    // utils
    void new_deck();
    void new_deck(uint8 n);
    void shuffle_deck();
    const Card & get_card(uint16) const;
    const Card & deal_card();

    // info
    uint16 remaining() const;
    uint16 deck_size() const;
    const Card * deck() const;
};

const char * card_str(const Card &);

} // namespace

#endif /* deck_h */
