#include "Programme.h"
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

bool Programme::isVpsStartValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Programme::setVpsStart(QString input) {
    if(input.isEmpty()) {
    return;
  }
  vpsStartValue = input;
  hasVpsStartValue = true;
  vpsStartRawValue = input;
}
void Programme::initVpsStart() {
  vpsStartValue = QString();
}
bool Programme::isChannelValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Programme::setChannel(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  channelValue = collapsed;
  hasChannelValue = true;
  channelRawValue = input;
}
void Programme::initChannel() {
  channelValue = QString();
}
bool Programme::isShowviewValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Programme::setShowview(QString input) {
    if(input.isEmpty()) {
    return;
  }
  showviewValue = input;
  hasShowviewValue = true;
  showviewRawValue = input;
}
void Programme::initShowview() {
  showviewValue = QString();
}
bool Programme::isStartValid(QString input) {
  bool ok;
    QString normalized = input.remove(QRegExp(" [+-].*$")).remove(QRegExp("[^0-9]"));
  if(normalized.isEmpty()) {
    ok = false;
  } else {
    QDateTime date_ = QDateTime::fromString(normalized, QString("yyyyMMddHHmmss").left(normalized.length()));
    ok = date_.isValid();
  }
  return ok;
}
void Programme::setStart(QString input) {
  QString normalized = input.remove(QRegExp(" [+-].*$")).remove(QRegExp("[^0-9]"));
  bool ok;
  QDateTime date_;  if(normalized.isEmpty()) {
    ok = false;
  } else {
    date_ = QDateTime::fromString(normalized, QString("yyyyMMddHHmmss").left(normalized.length()));
    ok = date_.isValid();
  }  if(ok) {
    startValue = date_;
  } else {
    return;
  }
  hasStartValue = true;
  startRawValue = input;
}
void Programme::initStart() {
  startValue = QDateTime();
}
bool Programme::isStopValid(QString input) {
  bool ok;
    QString normalized = input.remove(QRegExp(" [+-].*$")).remove(QRegExp("[^0-9]"));
  if(normalized.isEmpty()) {
    ok = false;
  } else {
    QDateTime date_ = QDateTime::fromString(normalized, QString("yyyyMMddHHmmss").left(normalized.length()));
    ok = date_.isValid();
  }
  return ok;
}
void Programme::setStop(QString input) {
  QString normalized = input.remove(QRegExp(" [+-].*$")).remove(QRegExp("[^0-9]"));
  bool ok;
  QDateTime date_;  if(normalized.isEmpty()) {
    ok = false;
  } else {
    date_ = QDateTime::fromString(normalized, QString("yyyyMMddHHmmss").left(normalized.length()));
    ok = date_.isValid();
  }  if(ok) {
    stopValue = date_;
  } else {
    return;
  }
  hasStopValue = true;
  stopRawValue = input;
}
void Programme::initStop() {
  stopValue = QDateTime();
}
bool Programme::isClumpidxValid(QString input) {
  bool ok;
  ok = !input.trimmed().isEmpty();
  return ok;
}
void Programme::setClumpidx(QString input) {
    if(input.trimmed().isEmpty()) {
    return;
  }
  QString normalized = input.replace(QChar(9), QChar(32)).replace(QChar(10), QChar(32)).replace(QChar(13), QChar(32));
  QString trimmed = normalized.trimmed();
  QString collapsed = trimmed.split(" ", QString::SkipEmptyParts).join(" ");
  clumpidxValue = collapsed;
  hasClumpidxValue = true;
  clumpidxRawValue = input;
}
void Programme::initClumpidx() {
  clumpidxValue = QString();
  setClumpidx("0/1");
}
bool Programme::isPdcStartValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Programme::setPdcStart(QString input) {
    if(input.isEmpty()) {
    return;
  }
  pdcStartValue = input;
  hasPdcStartValue = true;
  pdcStartRawValue = input;
}
void Programme::initPdcStart() {
  pdcStartValue = QString();
}
bool Programme::isVideoplusValid(QString input) {
  bool ok;
  ok = !input.isEmpty();
  return ok;
}
void Programme::setVideoplus(QString input) {
    if(input.isEmpty()) {
    return;
  }
  videoplusValue = input;
  hasVideoplusValue = true;
  videoplusRawValue = input;
}
void Programme::initVideoplus() {
  videoplusValue = QString();
}
void Programme::addIcon(Icon * ele) {
  iconList.append(ele);
}
void Programme::initIcon() {
  iconList = QList<Icon*>();
}
void Programme::addCategory(Category * ele) {
  categoryList.append(ele);
}
void Programme::initCategory() {
  categoryList = QList<Category*>();
}
void Programme::addSubTitle(SubTitle * ele) {
  subTitleList.append(ele);
}
void Programme::initSubTitle() {
  subTitleList = QList<SubTitle*>();
}
void Programme::addLastChance(LastChance * ele) {
  lastChanceList.append(ele);
}
void Programme::initLastChance() {
  lastChanceList = QList<LastChance*>();
}
void Programme::addAudio(Audio * ele) {
  audioList.append(ele);
}
void Programme::initAudio() {
  audioList = QList<Audio*>();
}
void Programme::addSubtitles(Subtitles * ele) {
  subtitlesList.append(ele);
}
void Programme::initSubtitles() {
  subtitlesList = QList<Subtitles*>();
}
void Programme::addDate(Date * ele) {
  dateList.append(ele);
}
void Programme::initDate() {
  dateList = QList<Date*>();
}
void Programme::addPreviouslyShown(PreviouslyShown * ele) {
  previouslyShownList.append(ele);
}
void Programme::initPreviouslyShown() {
  previouslyShownList = QList<PreviouslyShown*>();
}
void Programme::addCountry(Country * ele) {
  countryList.append(ele);
}
void Programme::initCountry() {
  countryList = QList<Country*>();
}
void Programme::addOrigLanguage(OrigLanguage * ele) {
  origLanguageList.append(ele);
}
void Programme::initOrigLanguage() {
  origLanguageList = QList<OrigLanguage*>();
}
void Programme::addStarRating(StarRating * ele) {
  starRatingList.append(ele);
}
void Programme::initStarRating() {
  starRatingList = QList<StarRating*>();
}
void Programme::addCredits(Credits * ele) {
  creditsList.append(ele);
}
void Programme::initCredits() {
  creditsList = QList<Credits*>();
}
void Programme::addTitle(Title * ele) {
  titleList.append(ele);
}
void Programme::initTitle() {
  titleList = QList<Title*>();
}
void Programme::addVideo(Video * ele) {
  videoList.append(ele);
}
void Programme::initVideo() {
  videoList = QList<Video*>();
}
void Programme::addNew(New * ele) {
  newList.append(ele);
}
void Programme::initNew() {
  newList = QList<New*>();
}
void Programme::addRating(Rating * ele) {
  ratingList.append(ele);
}
void Programme::initRating() {
  ratingList = QList<Rating*>();
}
void Programme::addEpisodeNum(EpisodeNum * ele) {
  episodeNumList.append(ele);
}
void Programme::initEpisodeNum() {
  episodeNumList = QList<EpisodeNum*>();
}
void Programme::addLength(Length * ele) {
  lengthList.append(ele);
}
void Programme::initLength() {
  lengthList = QList<Length*>();
}
void Programme::addUrl(Url * ele) {
  urlList.append(ele);
}
void Programme::initUrl() {
  urlList = QList<Url*>();
}
void Programme::addReview(Review * ele) {
  reviewList.append(ele);
}
void Programme::initReview() {
  reviewList = QList<Review*>();
}
void Programme::addLanguage(Language * ele) {
  languageList.append(ele);
}
void Programme::initLanguage() {
  languageList = QList<Language*>();
}
void Programme::addPremiere(Premiere * ele) {
  premiereList.append(ele);
}
void Programme::initPremiere() {
  premiereList = QList<Premiere*>();
}
void Programme::addDesc(Desc * ele) {
  descList.append(ele);
}
void Programme::initDesc() {
  descList = QList<Desc*>();
}
Programme * Programme::fromElement(QDomElement &element) {
  Programme *programme_ = new Programme();
  QDomNodeList list_ = element.childNodes();
  for (int i = 0; i < list_.size(); i++) {
    if (list_.at(i).isElement()) {
      QDomElement e = list_.at(i).toElement();
      programme_->addSubElement(e);
    }
  }
  QDomNamedNodeMap attrs_ = element.attributes();
  for(int i = 0; i<attrs_.size(); i++) {
    QDomAttr a = attrs_.item(i).toAttr();
    programme_->setAttribute(a);
  }
  return programme_;
}
void Programme::addSubElement( QDomElement &element) {
  if(element.localName().compare("Icon", Qt::CaseInsensitive)==0) {
    Icon *cn = Icon::fromElement(element);
    addIcon(cn);
    return;
  }
  if(element.localName().compare("Category", Qt::CaseInsensitive)==0) {
    Category *cn = Category::fromElement(element);
    addCategory(cn);
    return;
  }
  if(element.localName().compare("SubTitle", Qt::CaseInsensitive)==0) {
    SubTitle *cn = SubTitle::fromElement(element);
    addSubTitle(cn);
    return;
  }
  if(element.localName().compare("LastChance", Qt::CaseInsensitive)==0) {
    LastChance *cn = LastChance::fromElement(element);
    addLastChance(cn);
    return;
  }
  if(element.localName().compare("Audio", Qt::CaseInsensitive)==0) {
    Audio *cn = Audio::fromElement(element);
    addAudio(cn);
    return;
  }
  if(element.localName().compare("Subtitles", Qt::CaseInsensitive)==0) {
    Subtitles *cn = Subtitles::fromElement(element);
    addSubtitles(cn);
    return;
  }
  if(element.localName().compare("Date", Qt::CaseInsensitive)==0) {
    Date *cn = Date::fromElement(element);
    addDate(cn);
    return;
  }
  if(element.localName().compare("PreviouslyShown", Qt::CaseInsensitive)==0) {
    PreviouslyShown *cn = PreviouslyShown::fromElement(element);
    addPreviouslyShown(cn);
    return;
  }
  if(element.localName().compare("Country", Qt::CaseInsensitive)==0) {
    Country *cn = Country::fromElement(element);
    addCountry(cn);
    return;
  }
  if(element.localName().compare("OrigLanguage", Qt::CaseInsensitive)==0) {
    OrigLanguage *cn = OrigLanguage::fromElement(element);
    addOrigLanguage(cn);
    return;
  }
  if(element.localName().compare("StarRating", Qt::CaseInsensitive)==0) {
    StarRating *cn = StarRating::fromElement(element);
    addStarRating(cn);
    return;
  }
  if(element.localName().compare("Credits", Qt::CaseInsensitive)==0) {
    Credits *cn = Credits::fromElement(element);
    addCredits(cn);
    return;
  }
  if(element.localName().compare("Title", Qt::CaseInsensitive)==0) {
    Title *cn = Title::fromElement(element);
    addTitle(cn);
    return;
  }
  if(element.localName().compare("Video", Qt::CaseInsensitive)==0) {
    Video *cn = Video::fromElement(element);
    addVideo(cn);
    return;
  }
  if(element.localName().compare("New", Qt::CaseInsensitive)==0) {
    New *cn = New::fromElement(element);
    addNew(cn);
    return;
  }
  if(element.localName().compare("Rating", Qt::CaseInsensitive)==0) {
    Rating *cn = Rating::fromElement(element);
    addRating(cn);
    return;
  }
  if(element.localName().compare("EpisodeNum", Qt::CaseInsensitive)==0) {
    EpisodeNum *cn = EpisodeNum::fromElement(element);
    addEpisodeNum(cn);
    return;
  }
  if(element.localName().compare("Length", Qt::CaseInsensitive)==0) {
    Length *cn = Length::fromElement(element);
    addLength(cn);
    return;
  }
  if(element.localName().compare("Url", Qt::CaseInsensitive)==0) {
    Url *cn = Url::fromElement(element);
    addUrl(cn);
    return;
  }
  if(element.localName().compare("Review", Qt::CaseInsensitive)==0) {
    Review *cn = Review::fromElement(element);
    addReview(cn);
    return;
  }
  if(element.localName().compare("Language", Qt::CaseInsensitive)==0) {
    Language *cn = Language::fromElement(element);
    addLanguage(cn);
    return;
  }
  if(element.localName().compare("Premiere", Qt::CaseInsensitive)==0) {
    Premiere *cn = Premiere::fromElement(element);
    addPremiere(cn);
    return;
  }
  if(element.localName().compare("Desc", Qt::CaseInsensitive)==0) {
    Desc *cn = Desc::fromElement(element);
    addDesc(cn);
    return;
  }
}
void Programme::setAttribute( QDomAttr &attr) {
  if(attr.localName().compare("VpsStart", Qt::CaseInsensitive)==0) {
    setVpsStart(attr.value());
    return;
  }
  if(attr.localName().compare("Channel", Qt::CaseInsensitive)==0) {
    setChannel(attr.value());
    return;
  }
  if(attr.localName().compare("Showview", Qt::CaseInsensitive)==0) {
    setShowview(attr.value());
    return;
  }
  if(attr.localName().compare("Start", Qt::CaseInsensitive)==0) {
    setStart(attr.value());
    return;
  }
  if(attr.localName().compare("Stop", Qt::CaseInsensitive)==0) {
    setStop(attr.value());
    return;
  }
  if(attr.localName().compare("Clumpidx", Qt::CaseInsensitive)==0) {
    setClumpidx(attr.value());
    return;
  }
  if(attr.localName().compare("PdcStart", Qt::CaseInsensitive)==0) {
    setPdcStart(attr.value());
    return;
  }
  if(attr.localName().compare("Videoplus", Qt::CaseInsensitive)==0) {
    setVideoplus(attr.value());
    return;
  }
}
QDomDocument * Programme::loadXmlDocument(QFile & file) {
  if (!file.exists()) {
    qDebug() << "doesn't exist";
    return NULL;
  }
  QString errorStr;
  int errorLine;
  int errorColumn;
  QDomDocument *doc = new QDomDocument();
  if (!doc->setContent(&file, true, &errorStr, &errorLine, &errorColumn)) {
    qDebug()<< QString("Error > %1 < in file %2 on line %3, column %4").arg(
      errorStr).arg(file.fileName()).arg(errorLine).arg(errorColumn);
    delete doc;
    doc = NULL;
  }
  return doc;
}
Programme  * Programme::fromFile(QFile & file) {
  QDomDocument *doc = Programme::loadXmlDocument(file);
  if(doc==NULL) {
    return NULL;
  }
  QDomElement root = doc->documentElement();
  return Programme::fromElement(root);
}
