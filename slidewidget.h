/*
 *
Copyright (C) 2023  Gabriele Salvato

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/
#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QBasicTimer>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QFileInfoList>
#include <QTimer>


class SlideWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    SlideWidget();
    ~SlideWidget();

public:
    bool setSlideDir(QString sNewDir);
    bool startSlideShow();
    void stopSlideShow();
    void showFullScreen();

protected:
    void initializeGL() override;
    void paintGL() override;

    void initShaders();
    void initTextures();
    bool getLocations();

    bool prepareNextRound() ;
    bool prepareNextSlide();

public slots:
    void ontimerAnimateEvent();
    void onTimerSteadyEvent();
    void closeEvent(QCloseEvent*) override;

private:
    void initGeometry();
    void drawGeometry(QOpenGLShaderProgram *program);
    bool updateSlideList();

private:
    struct VertexData {
        QVector3D position;
        QVector2D texCoord;
    };
    QTimer timerAnimate;
    QTimer timerSteady;
    QVector<QOpenGLShaderProgram*> pPrograms;
    QOpenGLShaderProgram* pCurrentProgram;

    QOpenGLBuffer arrayBuf;
    QOpenGLTexture* pTexture0 = nullptr;
    QOpenGLTexture* pTexture1 = nullptr;

    QString sSlideDir;
    int iCurrentSlide;
    QFileInfoList slideList;
    int nVertices;
    int nAnimationTypes;
    bool bRunning;
    QImage* pBaseImage;
    QImage image;
    int currentAnimation;
    GLint     iTex0Loc;
    GLint     iTex1Loc;
    QMatrix4x4 m;
    GLint     iProgressLoc;
    GLfloat   progress;
    QScreen*  pMyScreen;
};
