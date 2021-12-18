//===-- ui/MainWindow.h - Main window of the UI ---------------------------===//
//
// Copyright (c) 2021 Jon Palmisciano; licensed under the BSD 3-Clause license.
//
// This file is part of AMU, an open source UI for the Wolfram Engine. The
// source code for AMU is available at <https://github.com/jonpalmisc/amu>.
//
//===----------------------------------------------------------------------===//

#pragma once

#include "Cell.h"

#include <amu/Engine.h>

#include <QMainWindow>
#include <QVBoxLayout>

/// Main application window.
class MainWindow : public QMainWindow {
    Q_OBJECT

    unsigned m_lastId;

    amu::Engine m_engine;

    QList<Cell*> m_cells;
    QVBoxLayout* m_rootLayout;

    /// Create a new cell and place it at the bottom of the notebook.
    void pushNewCell();

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    /// Evaluate a string under the connected engine.
    ///
    /// \param input The input (Wolfram Language) to evaluate
    QString engineEval(const QString& input) const;

public Q_SLOTS:

    /// Slot to signal that a cell has been evaluated.
    void cellEvaluated(unsigned id);
};
