const profile = {
    name: "Артём",
    topics: [
        {
            title: "HTML",
            total: 4,
            completed: 1,
        },
        {
            title: "CSS",
            total: 6,
            completed: 2,
        },
    ]
};

function getProgress(total, completed) {
    if (!Number.isInteger(total) || !Number.isInteger(completed))
        return null;

    if (total <= 0 || completed < 0 || completed > total)
        return null;

    return (completed / total) * 100;
}

function summarizeTopics(topics) {
    const output_topics = {
        total: 0,
        completed: 0,
        remaining: 0,
        percent: null,
        status: "Нет тем",
    }

    if (topics.length == 0)
        return output_topics;

    for (const topic of topics) {
        output_topics.total += topic.total;
        output_topics.completed += topic.completed;
    }

    output_topics.remaining = output_topics.total - output_topics.completed;
    output_topics.percent = Math.round(getProgress(output_topics.total, output_topics.completed));

    switch (output_topics.completed) {
        case 0:
            output_topics.status = "Ещё не начато";
            break;
        case output_topics.total:
            output_topics.status = "Завершено";
            break;
        default:
            output_topics.status = "В процессе";
            break;
    }

    return output_topics;
}

const summarizedTopics = summarizeTopics(profile.topics);
console.log(summarizedTopics);
console.log(`${profile.name}: завершено ${summarizedTopics.completed} из ${summarizedTopics.total} занятий (${summarizedTopics.percent}%). Осталось: ${summarizedTopics.remaining}. ${summarizedTopics.status}`);