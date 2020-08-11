/*!`
 * \file knitter_mock.cpp
 *
 * This file is part of AYAB.
 *
 *    AYAB is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    AYAB is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with AYAB.  If not, see <http://www.gnu.org/licenses/>.
 *
 *    Original Work Copyright 2013 Christian Obersteiner, Andreas Müller
 *    Modified Work Copyright 2020 Sturla Lange, Tom Price
 *    http://ayab-knitting.com
 */

#include <knitter.h>
#include <knitter_mock.h>

static KnitterMock *gKnitterMock = NULL;
KnitterMock *knitterMockInstance() {
  if (!gKnitterMock) {
    gKnitterMock = new KnitterMock();
  }
  return gKnitterMock;
}

void releaseKnitterMock() {
  if (gKnitterMock) {
    delete gKnitterMock;
    gKnitterMock = NULL;
  }
}

Machine_t Knitter::getMachineType() const {
  assert(gKnitterMock != NULL);
  return gKnitterMock->getMachineType();
}

void Knitter::setMachineType(Machine_t machineType) {
  assert(gKnitterMock != NULL);
  return gKnitterMock->setMachineType(machineType);
}

uint8_t Knitter::getStartOffset(const Direction_t direction) const {
  assert(gKnitterMock != NULL);
  return gKnitterMock->getStartOffset(direction);
}

bool Knitter::startTest() {
  assert(gKnitterMock != NULL);
  return gKnitterMock->startTest();
}

bool Knitter::startOperation(Machine_t machineType, uint8_t startNeedle,
                             uint8_t stopNeedle, uint8_t *pattern_start,
                             bool continuousReportingEnabled) {
  assert(gKnitterMock != NULL);
  return gKnitterMock->startOperation(machineType, startNeedle, stopNeedle,
                                      pattern_start,
                                      continuousReportingEnabled);
}

bool Knitter::setNextLine(uint8_t lineNumber) {
  assert(gKnitterMock != NULL);
  return gKnitterMock->setNextLine(lineNumber);
}

void Knitter::setLastLine() {
  assert(gKnitterMock != NULL);
  gKnitterMock->setLastLine();
}

void Knitter::send(uint8_t payload[], size_t length) {
  assert(gKnitterMock != NULL);
  gKnitterMock->send(payload, length);
}

void Knitter::onPacketReceived(const uint8_t *buffer, size_t size) {
  assert(gKnitterMock != NULL);
  gKnitterMock->onPacketReceived(buffer, size);
}

void Knitter::setState(OpState_t state) {
  assert(gKnitterMock != NULL);
  gKnitterMock->setState(state);
}

uint8_t Knitter::getStartNeedle() const {
  assert(gKnitterMock != NULL);
  return gKnitterMock->getStartNeedle();
}

uint8_t Knitter::getStopNeedle() const {
  assert(gKnitterMock != NULL);
  return gKnitterMock->getStopNeedle();
}

void Knitter::setStopNeedle(uint8_t stopNeedle) {
  assert(gKnitterMock != NULL);
  gKnitterMock->setStopNeedle(stopNeedle);
}

void Knitter::setPosition(uint8_t position) {
  assert(gKnitterMock != NULL);
  gKnitterMock->setPosition(position);
}

void Knitter::setDirection(Direction_t direction) {
  assert(gKnitterMock != NULL);
  gKnitterMock->setDirection(direction);
}

void Knitter::setCarriage(Carriage_t carriage) {
  assert(gKnitterMock != NULL);
  gKnitterMock->setCarriage(carriage);
}

void Knitter::setFirstRun(bool firstRun) {
  assert(gKnitterMock != NULL);
  gKnitterMock->setFirstRun(firstRun);
}

void Knitter::setWorkedOnLine(bool workedOnLine) {
  assert(gKnitterMock != NULL);
  gKnitterMock->setWorkedOnLine(workedOnLine);
}

void Knitter::setLineRequested(bool lineRequested) {
  assert(gKnitterMock != NULL);
  gKnitterMock->setLineRequested(lineRequested);
}

void Knitter::setLastLineFlag(bool lastLineFlag) {
  assert(gKnitterMock != NULL);
  gKnitterMock->setLastLineFlag(lastLineFlag);
}

Knitter *knitter;
