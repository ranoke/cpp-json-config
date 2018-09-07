/*
* Hikari Backend
*
* Copyright (C) 2018 RickyCorte
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#ifndef HIKARIBACKEND_LOGGING_H
#define HIKARIBACKEND_LOGGING_H

#define LOG_SHOW_CURRENT_DAY false
#ifndef _WIN32
#define SHOW_LOG_TIME
#endif
// #define FORCE_THREAD_SAFE


#include <iostream>
#include <ctime>
#include <mutex>


namespace RickyCorte
{

    namespace logging
    {
        /**
        * Get the current hour
        *
        * @param show_date pass true to show current day, month and year
        * @return formatted date string
        */
        static inline std::string getTimeString(bool show_date = false)
        {
            std::string date = "";
            time_t local = time(nullptr);
            struct tm *lt = localtime(&local);
            if (lt)
            {
                char dt[50];
                if (show_date)
                    strftime(dt, 50, "%d/%m/%Y %H:%M:%S %Z", lt);
                else
                    strftime(dt, 50, "%H:%M:%S %Z", lt);
                date = dt;
            }
            else
                date = "err";

            return date;
        }


        /**
        * Write to cout with mutex protection
        * @tparam T
        * @param data
        * @param new_line
        * @return
        */
        template<typename T>
        static inline void mutex_write(const T &data, bool new_line = false)
        {
#if FORCE_THREAD_SAFE
            static std::mutex mtx;
			std::lock_guard<std::mutex> guard(mtx);
#endif
            std::cout << data;

            if (new_line) std::cout << std::endl;
        }


        /**
        * Write base overload, writes to stdout the parameter t
        */
        template<typename T>
        static inline void write(const T &t)
        {
            mutex_write(t, true);
        }

        /**
        * Recursively writes to stdout the parameter list
        * No formatting is applied to parameters, they are placed in the submit order without separators
        */
        template<typename T, typename... Targs>
        static inline void write(const T &el, const Targs &... args)
        {
            mutex_write(el);
            write(args...);
        }

        /**
        * Recursively writes to stdout the parameter list with prefix and newline (1 per call)
        * No formatting is applied to parameters, they are placed in the submit order without separators
        */
        template<typename... Targs>
        static inline void console_message(const std::string &prefix, Targs... args)
        {
#ifdef SHOW_LOG_TIME
            std::cout << "[" << getTimeString(LOG_SHOW_CURRENT_DAY) << "] ";
#endif
            std::cout << prefix << " ";
            write(args...);
        }
    }
}

template <typename... Targs>
inline void RC_DEBUG(Targs... args)
{
#ifndef HIDE_DEBUG
    RickyCorte::logging::console_message("[DEBUG]", args...);
#endif // !HIDE_DEBUG
}

template <typename... Targs>
inline void RC_INFO(Targs... args)
{
#ifndef HIDE_INFO
    RickyCorte::logging::console_message("[INFO]", args...);
#endif // !HIDE_INFO
}

template <typename... Targs>
inline void RC_WARNING(Targs... args)
{
    RickyCorte::logging::console_message("[WARNING]", args...);
}

template <typename... Targs>
inline void RC_ERROR(Targs... args)
{
    RickyCorte::logging::console_message("[ERROR]", args...);
}

template <typename... Targs>
inline void RC_CRITICAL(Targs... args)
{
    RickyCorte::logging::console_message("[CRITICAL]", args...);
}

#endif //HIKARIBACKEND_LOGGING_H
