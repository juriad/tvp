#ifndef Programme_H_
#define Programme_H_
#include <QtCore/QtCore>
#include <QDomDocument>
#include "Icon.h"
#include "Category.h"
#include "SubTitle.h"
#include "LastChance.h"
#include "Audio.h"
#include "Subtitles.h"
#include "Date.h"
#include "PreviouslyShown.h"
#include "Country.h"
#include "OrigLanguage.h"
#include "StarRating.h"
#include "Credits.h"
#include "Title.h"
#include "Video.h"
#include "New.h"
#include "Rating.h"
#include "EpisodeNum.h"
#include "Length.h"
#include "Url.h"
#include "Review.h"
#include "Language.h"
#include "Premiere.h"
#include "Desc.h"

class Programme {
public:
Programme() {
  initIcon();
  initCategory();
  initSubTitle();
  initLastChance();
  initAudio();
  initSubtitles();
  initDate();
  initPreviouslyShown();
  initCountry();
  initOrigLanguage();
  initStarRating();
  initCredits();
  initTitle();
  initVideo();
  initNew();
  initRating();
  initEpisodeNum();
  initLength();
  initUrl();
  initReview();
  initLanguage();
  initPremiere();
  initDesc();
  initVpsStart();
  initChannel();
  initShowview();
  initStart();
  initStop();
  initClumpidx();
  initPdcStart();
  initVideoplus();
}
static Programme* fromFile( QFile &file);
static Programme* fromElement( QDomElement &element);
static QDomDocument * loadXmlDocument(QFile & file);
bool hasVpsStart() {
  return hasVpsStartValue;
}
bool isVpsStartValid(QString input);
QString getVpsStart() {
  return vpsStartValue;
}
QString getRawVpsStart() {
  return vpsStartRawValue;
}
bool hasChannel() {
  return hasChannelValue;
}
bool isChannelValid(QString input);
QString getChannel() {
  return channelValue;
}
QString getRawChannel() {
  return channelRawValue;
}
bool hasShowview() {
  return hasShowviewValue;
}
bool isShowviewValid(QString input);
QString getShowview() {
  return showviewValue;
}
QString getRawShowview() {
  return showviewRawValue;
}
bool hasStart() {
  return hasStartValue;
}
bool isStartValid(QString input);
QDateTime getStart() {
  return startValue;
}
QString getRawStart() {
  return startRawValue;
}
bool hasStop() {
  return hasStopValue;
}
bool isStopValid(QString input);
QDateTime getStop() {
  return stopValue;
}
QString getRawStop() {
  return stopRawValue;
}
bool hasClumpidx() {
  return hasClumpidxValue;
}
bool isClumpidxValid(QString input);
QString getClumpidx() {
  return clumpidxValue;
}
QString getRawClumpidx() {
  return clumpidxRawValue;
}
bool hasPdcStart() {
  return hasPdcStartValue;
}
bool isPdcStartValid(QString input);
QString getPdcStart() {
  return pdcStartValue;
}
QString getRawPdcStart() {
  return pdcStartRawValue;
}
bool hasVideoplus() {
  return hasVideoplusValue;
}
bool isVideoplusValid(QString input);
QString getVideoplus() {
  return videoplusValue;
}
QString getRawVideoplus() {
  return videoplusRawValue;
}
QList<Icon*> getIconList() {
  return iconList;
}
QList<Category*> getCategoryList() {
  return categoryList;
}
QList<SubTitle*> getSubTitleList() {
  return subTitleList;
}
QList<LastChance*> getLastChanceList() {
  return lastChanceList;
}
QList<Audio*> getAudioList() {
  return audioList;
}
QList<Subtitles*> getSubtitlesList() {
  return subtitlesList;
}
QList<Date*> getDateList() {
  return dateList;
}
QList<PreviouslyShown*> getPreviouslyShownList() {
  return previouslyShownList;
}
QList<Country*> getCountryList() {
  return countryList;
}
QList<OrigLanguage*> getOrigLanguageList() {
  return origLanguageList;
}
QList<StarRating*> getStarRatingList() {
  return starRatingList;
}
QList<Credits*> getCreditsList() {
  return creditsList;
}
QList<Title*> getTitleList() {
  return titleList;
}
QList<Video*> getVideoList() {
  return videoList;
}
QList<New*> getNewList() {
  return newList;
}
QList<Rating*> getRatingList() {
  return ratingList;
}
QList<EpisodeNum*> getEpisodeNumList() {
  return episodeNumList;
}
QList<Length*> getLengthList() {
  return lengthList;
}
QList<Url*> getUrlList() {
  return urlList;
}
QList<Review*> getReviewList() {
  return reviewList;
}
QList<Language*> getLanguageList() {
  return languageList;
}
QList<Premiere*> getPremiereList() {
  return premiereList;
}
QList<Desc*> getDescList() {
  return descList;
}

private:
void addSubElement( QDomElement &element);
void setAttribute( QDomAttr &attr);
QString vpsStartValue;
QString vpsStartRawValue;
bool hasVpsStartValue;
void setVpsStart(QString input);
void initVpsStart();
QString channelValue;
QString channelRawValue;
bool hasChannelValue;
void setChannel(QString input);
void initChannel();
QString showviewValue;
QString showviewRawValue;
bool hasShowviewValue;
void setShowview(QString input);
void initShowview();
QDateTime startValue;
QString startRawValue;
bool hasStartValue;
void setStart(QString input);
void initStart();
QDateTime stopValue;
QString stopRawValue;
bool hasStopValue;
void setStop(QString input);
void initStop();
QString clumpidxValue;
QString clumpidxRawValue;
bool hasClumpidxValue;
void setClumpidx(QString input);
void initClumpidx();
QString pdcStartValue;
QString pdcStartRawValue;
bool hasPdcStartValue;
void setPdcStart(QString input);
void initPdcStart();
QString videoplusValue;
QString videoplusRawValue;
bool hasVideoplusValue;
void setVideoplus(QString input);
void initVideoplus();
QList<Icon*> iconList;
void addIcon(Icon * ele);
void initIcon();
QList<Category*> categoryList;
void addCategory(Category * ele);
void initCategory();
QList<SubTitle*> subTitleList;
void addSubTitle(SubTitle * ele);
void initSubTitle();
QList<LastChance*> lastChanceList;
void addLastChance(LastChance * ele);
void initLastChance();
QList<Audio*> audioList;
void addAudio(Audio * ele);
void initAudio();
QList<Subtitles*> subtitlesList;
void addSubtitles(Subtitles * ele);
void initSubtitles();
QList<Date*> dateList;
void addDate(Date * ele);
void initDate();
QList<PreviouslyShown*> previouslyShownList;
void addPreviouslyShown(PreviouslyShown * ele);
void initPreviouslyShown();
QList<Country*> countryList;
void addCountry(Country * ele);
void initCountry();
QList<OrigLanguage*> origLanguageList;
void addOrigLanguage(OrigLanguage * ele);
void initOrigLanguage();
QList<StarRating*> starRatingList;
void addStarRating(StarRating * ele);
void initStarRating();
QList<Credits*> creditsList;
void addCredits(Credits * ele);
void initCredits();
QList<Title*> titleList;
void addTitle(Title * ele);
void initTitle();
QList<Video*> videoList;
void addVideo(Video * ele);
void initVideo();
QList<New*> newList;
void addNew(New * ele);
void initNew();
QList<Rating*> ratingList;
void addRating(Rating * ele);
void initRating();
QList<EpisodeNum*> episodeNumList;
void addEpisodeNum(EpisodeNum * ele);
void initEpisodeNum();
QList<Length*> lengthList;
void addLength(Length * ele);
void initLength();
QList<Url*> urlList;
void addUrl(Url * ele);
void initUrl();
QList<Review*> reviewList;
void addReview(Review * ele);
void initReview();
QList<Language*> languageList;
void addLanguage(Language * ele);
void initLanguage();
QList<Premiere*> premiereList;
void addPremiere(Premiere * ele);
void initPremiere();
QList<Desc*> descList;
void addDesc(Desc * ele);
void initDesc();

};
#endif