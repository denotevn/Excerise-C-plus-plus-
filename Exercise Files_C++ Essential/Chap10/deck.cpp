// deck.cpp by Bill Weinman <http://bw.org/>
// updated 2002-07-27

#include "deck.h"

namespace BW {

// MARK: - ctors

Deck::~Deck() {
    _delete_deck();
}

void Deck::_init() {
    srand((unsigned) time(nullptr));  // seed rand for later
    rand();     // this helps on some systems (MSVC)
    _create_deck();
    shuffle_deck();
    return;
}

void Deck::_delete_deck() {
    if(_deck) delete [] _deck;
    _deck = nullptr;
    _remaining_count = 0;
}

// move ctor
Deck::Deck(Deck && old) noexcept {
    // metadata
    _cards_per_deck = old._cards_per_deck;
    _numdecks = old._numdecks;

    // move the deck
    _deck = old._deck;
    _remaining_count = old._remaining_count;

    // reset old deck
    old._deck = nullptr;
    old._delete_deck();
}

// MARK: - utilities

void Deck::_init_deck() {
    _delete_deck();
    if(_numdecks > max_decks) throw E("Deck: too many decks (max 10)");
    _remaining_count = _numdecks * _cards_per_deck;
    _deck = new Card[_remaining_count];
}

// _create_deck()
// suit is 0-3 (cdhs); rank is 0-12 (A23456789TJQK)
void Deck::_create_deck() {
    _init_deck();
    uint16 cardnum = 0;   // array index starts at 0
    for(uint8 n_deck = 0; n_deck < _numdecks; ++n_deck) {
        uint8 n_suit = 0;
        for(; n_suit < suitcount; ++n_suit) {
            uint8 n_rank = 0;
            for(; n_rank < rankcount; ++n_rank) {
                _deck[cardnum].suit = n_suit;
                _deck[cardnum].rank = n_rank;
                ++cardnum;
            }
        }
    }
}

void Deck::new_deck() {
    _create_deck();
    shuffle_deck();
}

void Deck::new_deck(uint8 n) {
    _numdecks = n;
    _create_deck();
    shuffle_deck();
}

void Deck::shuffle_deck() {
    uint16 ncards = remaining();
    
    for (uint16 i = 0; i < ncards; ++i) {
        uint16 r = i + (rand() % (ncards - i));
        if(r != i) std::swap(_deck[r], _deck[i]);
    }
}

const Card & Deck::get_card(uint16 index) const {
    if(index >= _remaining_count) throw E("Deck: card out of range");
    return _deck[index];
}

const Card & Deck::deal_card() {
    if(_remaining_count == 0) throw E("Deck: cannot deal from empty deck");
    return _deck[--_remaining_count];
}

// MARK: - info

uint16 Deck::deck_size() const {
    return _cards_per_deck * _numdecks;
}

uint16 Deck::remaining() const {
    return _remaining_count;
}

const Card * Deck::deck() const {
    return _deck;
}

// MARK:: - non-member functions

const char * card_str(const Card & c) {
    static char outstr[3] = { 'x', 'x', 0 };
    char & outstr_rank = outstr[0];
    char & outstr_suit = outstr[1];
    
    if(c.rank == 0) outstr_rank = facecards[0];    // rank 0 is A
    else if(c.rank > 8) outstr_rank = facecards[c.rank - 8];   // T J Q K
    else outstr_rank = c.rank + '1';   // numeric cards

    outstr_suit = suitstr[c.suit];
    return (const char *) outstr;
}

} // namespace

