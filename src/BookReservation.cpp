#include "../include/BookReservation.h"
#include "../include/LExceptions.h"


/**
 * Constructs a ReservationRecord with patron and book information.
 *
 * @param patronID The ID of the patron making the reservation.
 * @param bookISBN The ISBN of the book being reserved.
 */
ReservationRecord::ReservationRecord(std::string &patronID, std::string &bookISBN) {
    this->patronID = patronID;
    this->bookISBN = bookISBN;
}


/**
 * Constructs a ReservationRecord with patron and book information.
 *
 * @param patron The Patron object making the reservation.
 * @param book The Book object being reserved.
 */
ReservationRecord::ReservationRecord(const Patron &patron, const Book &book) {
    this->patronID = patron.ID;
    this->bookISBN = book.ISBN;
}


/**
 * Constructs a BookReservationManagementSystem with a maximum number of pending reservations.
 *
 * @param maxPendingReservations The maximum number of pending reservations allowed.
 */
BookReservationManagementSystem::BookReservationManagementSystem(int maxPendingReservations)
    : maxPendingReservations(maxPendingReservations) {}


/**
* Indexes a book into the system's book database.
*
* @param book The Book object to be added to the database.
*/
void BookReservationManagementSystem::indexBookToDB(const Book &book) {
    booksDB.push_back(book);
}


/**
 * Enqueues a reservation into the system's pending reservations.
 *
 * @param patron The Patron object making the reservation.
 * @param book The Book object being reserved.
 */
void BookReservationManagementSystem::enqueueReservation(const Patron &patron, const Book &book) {
    ReservationRecord rr(patron, book);
    pendingReservations.enqueue(rr);
}


/**
 * Enqueues a reservation into the system's pending reservations.
 *
 * @param reservation The ReservationRecord object to be added to pending reservations.
 */
void BookReservationManagementSystem::enqueueReservation(const ReservationRecord &reservation) {
    pendingReservations.enqueue(reservation);
}


/**
 * Processes the next reservation from the pendingReservations queue.
 *
 * @return The ReservationRecord of the reservation that was processed.
 *
 * @throws ReservationRecordUnavailable if there are no pending reservations to process.
 */
ReservationRecord BookReservationManagementSystem::processReservation() {
    int rotationCount = 0;

    if (pendingReservations.isEmpty()) {
        throw ReservationRecordUnavailable();
    }
    else {
        while (!pendingReservations.isEmpty()) {
            ReservationRecord currentReservation = pendingReservations.front();
            // Search pending reservation's book is in booksDB
            for (auto &i : booksDB) {
                if (currentReservation.bookISBN == i.ISBN && i.copies >= 1) {
                    fulfilledReservations.push(currentReservation);
                    pendingReservations.dequeue();
                    i.copies--;
                    return currentReservation;
                }
            }
            // Add currentReservation to the end of queue if it's not exist in booksDB(copies = 0)
            pendingReservations.enqueue(currentReservation);
            pendingReservations.dequeue();
            rotationCount++;
            if (rotationCount == pendingReservations.size())
                // if rotated queue more than queue size, throw exception
                throw ReservationRecordUnavailable();
        }
    }
}



