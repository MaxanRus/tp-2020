#include "WeatherTestCase.h"
#include "WeatherMock.h"

float FakeWeather::GetRand() {
  return float(rnd() % 1000) / 100.0;
}
cpr::Response FakeWeather::Get(const std::string& city, const cpr::Url& url) {
  cpr::Response response;
  response.text = "{\"main\":{\"temp\":" + std::to_string(GetRand()) + "},\"list\":[\"0\",\"1\",\"2\",\"3\",\"4\",\"5\",\"6\",{\"main\":{\"temp\":" + std::to_string(GetRand()) + "}}]}";
  response.status_code = 200;
  return response;
}
cpr::Response FakeWeatherFailLoadResponse::Get(const std::string& city, const cpr::Url& url) {
  cpr::Response response;
  response.status_code = 201;
  return response;
}

TEST(Weather, TestAllFunctionsInWeather) {
  FakeWeather fake_weather;
  for (int i = 0; i < 10000; ++i) {
    fake_weather.FindDiffBetweenTwoCities("Moscow", "Moscow");
    fake_weather.FindDiffBetweenTwoCities("London", "New-York");
    fake_weather.GetTomorrowTemperature("Krasnodar");
    fake_weather.GetTomorrowDiff("Omsk");
    fake_weather.SetApiKey("Minsk");
    fake_weather.GetTomorrowTemperature("Kiev");
    fake_weather.GetDifferenceString("Volgograd", "Saint-Petersburg");
  }
}

TEST(Weather, TestTrowInWeather) {
  FakeWeatherFailLoadResponse fake_weather_fail_load_response;
  EXPECT_THROW(fake_weather_fail_load_response.GetDifferenceString("Omereka", "RaSSiYA"),
               std::invalid_argument);
}
