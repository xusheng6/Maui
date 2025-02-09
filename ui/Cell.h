//===-- ui/Cell.h - Notebook cell widget ----------------------------------===//
//
// Copyright (c) 2021 Jon Palmisciano; licensed under the BSD 3-Clause license.
//
// This file is part of Maui, an open source UI for the Wolfram Engine. The
// source code for Maui is available at <https://github.com/jonpalmisc/Maui>.
//
//===----------------------------------------------------------------------===//

#pragma once

#include <QLabel>
#include <QLineEdit>

class MainWindow;

/// A notebook cell.
class Cell : public QWidget {
    Q_OBJECT

    MainWindow* m_mainWindow;
    unsigned m_id;

    QWidget* m_inputSubcell;
    QWidget* m_outputSubcell;

    QLabel* m_inputLabel;
    QLineEdit* m_inputField;

    QLabel* m_outputLabel;
    QLabel* m_outputField;

public:
    Cell(MainWindow* mainWindow, unsigned id = 0, QWidget* parent = nullptr);

    /// Get the cell's ID.
    unsigned id() const { return m_id; }

    /// Set the cell's ID and update the input/output labels.
    void setId(unsigned id);

    /// Evaluate the cell's current input
    void evaluateCurrentInput();
};
