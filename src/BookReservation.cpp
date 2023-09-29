#include "../include/BookReservation.h"
#include "../include/LExceptions.h"

ReservationRecord::ReservationRecord(std::string &patronID, std::string &bookISBN) {
    this->patronID = patronID;
    this->bookISBN = bookISBN;
}

ReservationRecord::ReservationRecord(const Patron &patron, const Book &book) {
    this->patronID = patron.ID;
    this->bookISBN = book.ISBN;
}


BookReservationManagementSystem::BookReservationManagementSystem(int maxPendingReservations)
    : maxPendingReservations(maxPendingReservations) {}


void BookReservationManagementSystem::indexBookToDB(const Book &book) {
    booksDB.push_back(book);
}

void BookReservationManagementSystem::enqueueReservation(const Patron &patron, const Book &book) {
    ReservationRecord rr(patron, book);
    pendingReservations.enqueue(rr);
}


void BookReservationManagementSystem::enqueueReservation(const ReservationRecord &reservation) {
    pendingReservations.enqueue(reservation);
}

ReservationRecord BookReservationManagementSystem::processReservation() {

    throw ReservationRecordUnavailable();
}




