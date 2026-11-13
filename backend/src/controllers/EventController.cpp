#include "EventController.h"
#include <string>
#include <jsoncpp/json/json.h>

void EventController::GetEvents(
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback
    ) {
        Json::Value response;
        Json::Value events(Json::arrayValue);
        Json::Value event;

        event["id"] = 1;
        event["title"] = "Сходка любителей бэкенда на c++";
        event["place"] = "Кронва";

        events.append(event);

        Json::Value event2;

        event2["id"] = 2;
        event2["title"] = "Сходка моих фанатов";
        event2["place"] = "Ломо";

        events.append(event2);
        response["events"] = events;
        auto httpResponse = drogon::HttpResponse::newHttpJsonResponse(response);
        callback(httpResponse);
    }

void EventController::PostEvent(
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback
    ) {
        auto response = drogon::HttpResponse::newHttpResponse();
        response->setBody("Скоро можно будет добавлять события! (но надо быть админом)");
        callback(response);
    }

void EventController::GetEventById(
        const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback,
        int event_id
    ) {
        auto response = drogon::HttpResponse::newHttpResponse();
        response->setBody(
            "Скоро можно будет получать событие по id = " +
            std::to_string(event_id)
        );
        callback(response);
    }

void EventController::EditEventById(
    const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback,
        int event_id
) {
    auto response = drogon::HttpResponse::newHttpResponse();
        response->setBody(
            "Скоро можно будет изменять событие по id = " +
            std::to_string(event_id)
        );
        callback(response);
}

void EventController::RemoveEventById(
    const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback,
        int event_id
) {
    auto response = drogon::HttpResponse::newHttpResponse();
        response->setBody(
            "Скоро можно будет удалять событие по id = " +
            std::to_string(event_id)
        );
        callback(response);
}

void EventController::GetCategories(
    const drogon::HttpRequestPtr& req,
        std::function<void(const drogon::HttpResponsePtr&)>&& callback
) {
    auto response = drogon::HttpResponse::newHttpResponse();
        response->setBody("Скоро можно будет просматривать категории!");
        callback(response);
}